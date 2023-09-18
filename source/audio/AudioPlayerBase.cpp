#include "../../include/audio/AudioPlayerBase.h"

AudioPlayerBase::~AudioPlayerBase(){
    unload();
}

void AudioPlayerBase::play(){
    stop();
    ndspChnInitParams(channel);
    ndspChnSetInterp(channel,interp);
    ndspChnSetRate(channel, rate);
    ndspChnSetFormat(channel, NDSP_CHANNELS(channels) | NDSP_ENCODING(encoding));
    ndspChnWaveBufAdd(channel, &waveBuf[0]);
}

void AudioPlayerBase::stop(){
    ndspChnWaveBufClear(channel);
    ndspChnReset(channel);
}

void AudioPlayerBase::unload(){
    loaded = false;
    linearFree(waveBuf);
    linearFree(data);
}

bool AudioPlayerBase::isLoaded(){
    return loaded;
}

bool AudioPlayerBase::isPlaying(){
    return ndspChnIsPlaying(channel);
}