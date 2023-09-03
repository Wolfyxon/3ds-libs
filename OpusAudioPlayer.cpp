#include "OpusAudioPlayer.h"

OpusAudioPlayer::OpusAudioPlayer(){

}

OpusAudioPlayer::~OpusAudioPlayer() {
    
}

bool OpusAudioPlayer::load(const std::string& filePath) {
    int error;
    opusFile = op_open_file(filePath.c_str(), &error);
    if (!opusFile) return false;

    return true;
}

void OpusAudioPlayer::play() {

}
