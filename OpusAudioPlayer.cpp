#include "OpusAudioPlayer.h"

OpusAudioPlayer::OpusAudioPlayer()
    : opusFile(nullptr), volume(1.0f), paused(false), playing(false) {
    memset(audioBuffer, 0, sizeof(audioBuffer));
}

OpusAudioPlayer::~OpusAudioPlayer() {
    close();
}

bool OpusAudioPlayer::load(const std::string& filePath) {
    close();

    int error;
    opusFile = op_open_file(filePath.c_str(), &error);
    if (!opusFile) return false;

    return true;
}

void OpusAudioPlayer::play() {
    if (!opusFile) return;

    if (paused) {
        if (playing) {
            ndspChnSetPaused(0, false);
        } else {
            playing = true;
            ndspChnWaveBufAdd(0, audioBuffer);
        }
        paused = false;
    } else {
        playing = true;
        ogg_int64_t pcm_offset = 0;
        u32 totalSamples = 0;
        int samples;
        while ((samples = op_read_stereo(opusFile, (opus_int16*)&audioBuffer, sizeof(audioBuffer) / 4)) > 0) {
            ndspChnWaveBufAdd(0, audioBuffer);
            totalSamples += samples;
            if (totalSamples >= 44100 * 5) {
                break;
            }
        }
    }
}

void OpusAudioPlayer::stop() {
    if (!playing) return;

    ndspChnWaveBufClear(0);
    playing = false;
}

void OpusAudioPlayer::pause() {
    if (!playing || paused) return;

    ndspChnSetPaused(0, true);
    paused = true;
}

void OpusAudioPlayer::resume() {
    if (!playing || !paused) return;

    ndspChnSetPaused(0, false);
    paused = false;
}

void OpusAudioPlayer::setVolume(float volume) {
    this->volume = volume;

    if (playing) {
        ndspAuxSetVolume(0, volume);
    }
}

void OpusAudioPlayer::close() {
    if (opusFile) {
        op_free(opusFile);
        opusFile = nullptr;
    }
    stop();
}