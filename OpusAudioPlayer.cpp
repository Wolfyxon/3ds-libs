#include "OpusAudioPlayer.h"

OpusAudioPlayer::OpusAudioPlayer(int channel_) {
    channel = channel_;
}

OpusAudioPlayer::~OpusAudioPlayer() {
    unload();
}

bool OpusAudioPlayer::load(char* filePath){
    int error = 0;
    opusFile = op_open_file(filePath, &error);
    if(error != 0) return false;
    if(opusFile == NULL) return false;

    return true;
}

void OpusAudioPlayer::unload(){
    op_free(opusFile);
}

bool OpusAudioPlayer::audioInit() {
    ndspChnReset(channel);
    ndspSetOutputMode(NDSP_OUTPUT_STEREO);
    ndspChnSetInterp(channel, NDSP_INTERP_POLYPHASE);
    ndspChnSetRate(channel, SAMPLE_RATE);
    ndspChnSetFormat(channel, NDSP_FORMAT_STEREO_PCM16);

    const size_t bufferSize = WAVEBUF_SIZE * ARRAY_SIZE(s_waveBufs);
    s_audioBuffer = (int16_t *)linearAlloc(bufferSize);
    if(!s_audioBuffer) {return false;}

    memset(&s_waveBufs, 0, sizeof(s_waveBufs));
    int16_t *buffer = s_audioBuffer;

    for(size_t i = 0; i < ARRAY_SIZE(s_waveBufs); ++i) {
        s_waveBufs[i].data_vaddr = buffer;
        s_waveBufs[i].status     = NDSP_WBUF_DONE;

        buffer += WAVEBUF_SIZE / sizeof(buffer[0]);
    }

    return true;
}

bool OpusAudioPlayer::play(){
    if(opusFile == NULL) return false;

}