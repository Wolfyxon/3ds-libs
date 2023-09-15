#include "AudioPlayerBase.h"
#include <ogg/ogg.h>
#include <tremor/ivorbisfile.h>

class OggAudioPlayer : public AudioPlayerBase {
    public:
        OggAudioPlayer() = default;
        virtual ~OggAudioPlayer() = default;

        OggVorbis_File ovf;

        /** Plays the audio */
        virtual void play() = 0;
        /** 
        * Loads OGG vorbis audio from the specified file path.
        * @param filePath Path to the .ogg audio file.
        */
        virtual AudioResult load(char* filePath) = 0;
};