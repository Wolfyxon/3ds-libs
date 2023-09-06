#include <3ds.h>
#include <opusfile.h>
#include <cstring>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

class OpusAudioPlayer {
public:
    OpusAudioPlayer(int channel_=0);
    ~OpusAudioPlayer();

    int channel = 0;
    OggOpusFile *opusFile = NULL;

    bool load(char* filePath);
    void unload();
    bool play();

private:
    static const int SAMPLE_RATE = 48000;            // Opus is fixed at 48kHz
    static const int SAMPLES_PER_BUF = SAMPLE_RATE * 120 / 1000;  // 120ms buffer
    static const int CHANNELS_PER_SAMPLE = 2;        // We ask libopusfile for
                                                 // stereo output; it will down
                                                 // -mix for us as necessary.

    static const int THREAD_AFFINITY = -1;           // Execute thread on any core
    static const int THREAD_STACK_SZ = 32 * 1024;    // 32kB stack for audio thread

    static const size_t WAVEBUF_SIZE = SAMPLES_PER_BUF * CHANNELS_PER_SAMPLE
    * sizeof(int16_t);                           // Size of NDSP wavebufs


    ndspWaveBuf s_waveBufs[3];
    int16_t *s_audioBuffer = NULL;

    bool audioInit();
};
