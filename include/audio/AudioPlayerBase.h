#include <3ds.h>
#include "../Classified.h"
#include "../debug.h"

enum AudioResult {
    success,
    file_not_found,
    not_enough_memory,
    codec_error,
    no_info,
    stream_no_data,
    stream_error,
};

class AudioPlayerBase : public Classified {
    friend class OggAudioPlayer;

    public:
        AudioPlayerBase() = default;
        virtual ~AudioPlayerBase() = default;

        ndspWaveBuf waveBuf[3];
        int channel = 0;
        bool loop = false;

        /** Plays the audio */
        virtual void play();
        /** 
         * Loads audio from the specified file path.
         * @param filePath Path to the audio file.
         */
        virtual AudioResult load(char* filePath) = 0;
        /** Unloads the loaded audio file. */
        virtual void unload();
        /** Checks if an audio file is loaded. */
        bool isLoaded();
    private:
        bool loaded = false;

    	float rate;
        char* data;
        ndspInterpType interp = NDSP_INTERP_NONE;
        u32 encoding = NDSP_ENCODING_PCM16;
	    u32 channels;
	    u32 samples;
	    u32 size;
    protected:
        static int occupiedChannels;
};