#ifndef OPUS_AUDIO_PLAYER_H
#define OPUS_AUDIO_PLAYER_H

#include <string>
#include <opusfile.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

class OpusAudioPlayer {
public:
    OpusAudioPlayer();
    ~OpusAudioPlayer();

    bool load(char* filePath);
    bool audioInit();

private:
    void audioCallback(void *const nul_);
    void audioThread(void *const opusFile_);
    bool fillBuffer(OggOpusFile *opusFile_, ndspWaveBuf *waveBuf_);
    void audioExit();
    void audioCallback(void *const nul_);
    void audioThread(void *const opusFile_);
};

#endif