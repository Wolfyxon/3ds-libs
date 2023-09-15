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

        ndspWaveBuf waveBuf[3];
        int channel = 0;
        bool loop = false;

        /** Plays the audio */
        virtual void play() = 0;
        /** 
         * Loads audio from the specified file path.
         * @param filePath Path to the audio file.
         */
        virtual AudioResult load(char* filePath) = 0;
    private:
    	float rate;
        char* data;
        ndspInterpType interp;
	    u32 channels;
	    u32 encoding;
	    u32 samples;
	    u32 size;
};