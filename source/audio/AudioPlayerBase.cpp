#include "../../include/audio/AudioPlayerBase.h"

void AudioPlayerBase::play(){
    ndspChnWaveBufClear(channel);
    ndspChnReset(channel);
    ndspChnInitParams(channel);
    ndspChnSetInterp(channel,interp);
    ndspChnSetRate(channel, rate);
    ndspChnSetFormat(channel, NDSP_CHANNELS(channels) | NDSP_ENCODING(encoding));
    ndspChnWaveBufAdd(channel, &waveBuf[0]);
}