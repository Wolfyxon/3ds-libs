#include "OpusAudioPlayer.h"

static const int SAMPLE_RATE = 48000;            // Opus is fixed at 48kHz
static const int SAMPLES_PER_BUF = SAMPLE_RATE * 120 / 1000;  // 120ms buffer
static const int CHANNELS_PER_SAMPLE = 2;        // We ask libopusfile for
                                                 // stereo output; it will down
                                                 // -mix for us as necessary.
static const int THREAD_AFFINITY = -1;           // Execute thread on any core
static const int THREAD_STACK_SZ = 32 * 1024;    // 32kB stack for audio thread
static const size_t WAVEBUF_SIZE = SAMPLES_PER_BUF * CHANNELS_PER_SAMPLE
    * sizeof(int16_t);   
ndspWaveBuf s_waveBufs[3];
int16_t *s_audioBuffer = NULL;
LightEvent s_event;
volatile bool s_quit = false;  // Quit flag

OpusAudioPlayer::OpusAudioPlayer(){

}

bool OpusAudioPlayer::load(char* filePath){
    int error = 0;
    OggOpusFile *op = op_open_file(filePath, &error);
    if(error) return false;

        ndspSetCallback(audioCallback, NULL);

    // Spawn audio thread

    // Set the thread priority to the main thread's priority ...
    int32_t priority = 0x30;
    svcGetThreadPriority(&priority, CUR_THREAD_HANDLE);
    // ... then subtract 1, as lower number => higher actual priority ...
    priority -= 1;
    // ... finally, clamp it between 0x18 and 0x3F to guarantee that it's valid.
    priority = priority < 0x18 ? 0x18 : priority;
    priority = priority > 0x3F ? 0x3F : priority;

    // Start the thread, passing our opusFile as an argument.
    const Thread threadId = threadCreate(audioThread, op,
                                         THREAD_STACK_SZ, priority,
                                         THREAD_AFFINITY, false);
}

// I have no idea what's going on below this line

void OpusAudioPlayer::audioCallback(void *const nul_) {
    (void)nul_;  // Unused

    if(s_quit) { // Quit flag
        return;
    }
    
    LightEvent_Signal(&s_event);
}

// Audio thread
// This handles calling the decoder function to fill NDSP buffers as necessary
void OpusAudioPlayer::audioThread(void *const opusFile_) {
    OggOpusFile *const opusFile = (OggOpusFile *)opusFile_;

    while(!s_quit) {  // Whilst the quit flag is unset,
                      // search our waveBufs and fill any that aren't currently
                      // queued for playback (i.e, those that are 'done')
        for(size_t i = 0; i < ARRAY_SIZE(s_waveBufs); ++i) {
            if(s_waveBufs[i].status != NDSP_WBUF_DONE) {
                continue;
            }
            
            if(!fillBuffer(opusFile, &s_waveBufs[i])) {   // Playback complete
                return;
            }
        }

        // Wait for a signal that we're needed again before continuing,
        // so that we can yield to other things that want to run
        // (Note that the 3DS uses cooperative threading)
        LightEvent_Wait(&s_event);
    }
}

bool OpusAudioPlayer::audioInit(void) {
    // Setup NDSP
    osSetSpeedupEnable(true);
    LightEvent_Init(&s_event, RESET_ONESHOT);
    ndspChnReset(0);
    ndspSetOutputMode(NDSP_OUTPUT_STEREO);
    ndspChnSetInterp(0, NDSP_INTERP_POLYPHASE);
    ndspChnSetRate(0, SAMPLE_RATE);
    ndspChnSetFormat(0, NDSP_FORMAT_STEREO_PCM16);

    // Allocate audio buffer
    const size_t bufferSize = WAVEBUF_SIZE * ARRAY_SIZE(s_waveBufs);
    s_audioBuffer = (int16_t *)linearAlloc(bufferSize);
    if(!s_audioBuffer) {
        return false;
    }

    // Setup waveBufs for NDSP
    memset(&s_waveBufs, 0, sizeof(s_waveBufs));
    int16_t *buffer = s_audioBuffer;

    for(size_t i = 0; i < ARRAY_SIZE(s_waveBufs); ++i) {
        s_waveBufs[i].data_vaddr = buffer;
        s_waveBufs[i].status     = NDSP_WBUF_DONE;

        buffer += WAVEBUF_SIZE / sizeof(buffer[0]);
    }

    return true;
}

void OpusAudioPlayer::audioExit(void) {
    ndspChnReset(0);
    linearFree(s_audioBuffer);
}

bool OpusAudioPlayer::fillBuffer(OggOpusFile *opusFile_, ndspWaveBuf *waveBuf_) {
    // Decode samples until our waveBuf is full
    int totalSamples = 0;
    while(totalSamples < SAMPLES_PER_BUF) {
        int16_t *buffer = waveBuf_->data_pcm16 + (totalSamples *
            CHANNELS_PER_SAMPLE);
        const size_t bufferSize = (SAMPLES_PER_BUF - totalSamples) *
            CHANNELS_PER_SAMPLE;

        // Decode bufferSize samples from opusFile_ into buffer,
        // storing the number of samples that were decoded (or error)
        const int samples = op_read_stereo(opusFile_, buffer, bufferSize);
        if(samples <= 0) {
            if(samples == 0) break;  // No error here
            break;
        }
        
        totalSamples += samples;
    }

    // If no samples were read in the last decode cycle, we're done
    if(totalSamples == 0) {
        printf("Playback complete, press Start to exit\n");
        return false;
    }

    // Pass samples to NDSP
    waveBuf_->nsamples = totalSamples;
    ndspChnWaveBufAdd(0, waveBuf_);
    DSP_FlushDataCache(waveBuf_->data_pcm16,
        totalSamples * CHANNELS_PER_SAMPLE * sizeof(int16_t));

    return true;
}

// NDSP audio frame callback
// This signals the audioThread to decode more things
// once NDSP has played a sound frame, meaning that there should be
// one or more available waveBufs to fill with more data.
void OpusAudioPlayer::audioCallback(void *const nul_) {
    (void)nul_;  // Unused

    if(s_quit) { // Quit flag
        return;
    }
    
    LightEvent_Signal(&s_event);
}

// Audio thread
// This handles calling the decoder function to fill NDSP buffers as necessary
void OpusAudioPlayer::audioThread(void *const opusFile_) {
    OggOpusFile *const opusFile = (OggOpusFile *)opusFile_;

    while(!s_quit) {  // Whilst the quit flag is unset,
                      // search our waveBufs and fill any that aren't currently
                      // queued for playback (i.e, those that are 'done')
        for(size_t i = 0; i < ARRAY_SIZE(s_waveBufs); ++i) {
            if(s_waveBufs[i].status != NDSP_WBUF_DONE) {
                continue;
            }
            
            if(!fillBuffer(opusFile, &s_waveBufs[i])) {   // Playback complete
                return;
            }
        }

        // Wait for a signal that we're needed again before continuing,
        // so that we can yield to other things that want to run
        // (Note that the 3DS uses cooperative threading)
        LightEvent_Wait(&s_event);
    }
}
