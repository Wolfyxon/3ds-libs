#include <3ds.h>
#include "../Classified.h"
#include "../debug.h"

class AudioPlayerBase : public Classified {
    public:
        AudioPlayerBase() = default;
        virtual ~AudioPlayerBase() = default;

        int channel = 0;

        /** Plays the audio */
        virtual void play() = 0;
        /** 
         * Loads audio from the specified file path.
         * @param filePath Path to the audio file.
         */
        virtual bool load(string filePath) = 0;
};