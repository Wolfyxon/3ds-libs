#include "AudioPlayerBase.h"
#include <tremor/ivorbisfile.h>
#include <ogg/ogg.h>

class OggAudioPlayer : public AudioPlayerBase {
    OggAudioPlayer() = default;
    virtual ~OggAudioPlayer() = default;
    
    /** Plays the audio */
    virtual void play() = 0;
    /** 
    * Loads OGG vorbis audio from the specified file path.
    * @param filePath Path to the .ogg audio file.
    */
    virtual AudioResult load(string filePath) = 0;
};