#ifndef OPUS_AUDIO_PLAYER_H
#define OPUS_AUDIO_PLAYER_H

#include <string>
#include <opusfile.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class OpusAudioPlayer {
public:
    OpusAudioPlayer();
    ~OpusAudioPlayer();

    bool load(const std::string& filePath);
    void play();

private:
    OggOpusFile* opusFile;
};

#endif