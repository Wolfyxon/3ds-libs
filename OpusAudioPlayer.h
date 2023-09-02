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
    void stop();
    void pause();
    void resume();
    void setVolume(float volume);

private:
    OggOpusFile* oggFile;
    float volume;
    bool paused;
    bool playing;
    ndspWaveBuf audioBuffer[16384]; // Adjust the buffer size as needed

    void close();
};

#endif // OPUS_AUDIO_PLAYER_H
