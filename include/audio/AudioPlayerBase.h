#include <3ds.h>
#include "../Classified.h"
#include "../debug.h"

enum AudioResult {
    success,
    file_not_found,
    not_enough_memory,
    codec_error,
    stream_no_data,
};

class AudioPlayerBase : public Classified {
    public:
        AudioPlayerBase() = default;
        virtual ~AudioPlayerBase() = default;

        int channel = 0;
        bool loop = false;

        /** Plays the audio */
        virtual void play() = 0;
        /** 
         * Loads audio from the specified file path.
         * @param filePath Path to the audio file.
         */
        virtual AudioResult load(string filePath) = 0;
};