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
    return !(error!=0 || opusFile == NULL);
}

void OpusAudioPlayer::unload(){
    op_free(opusFile);
}
