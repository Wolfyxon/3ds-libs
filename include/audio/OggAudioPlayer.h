#include "AudioPlayerBase.h"
#include <tremor/ivorbisfile.h>
#include <ogg/ogg.h>

class OggAudioPlayer : public AudioPlayerBase {
    OggAudioPlayer() = default;
    virtual ~OggAudioPlayer() = default;
    
};