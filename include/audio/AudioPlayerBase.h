#include <3ds.h>
#include "../Classified.h"
#include "../debug.h"

class AudioPlayerBase : public Classified {
    public:
        AudioPlayerBase() = default;
        virtual ~AudioPlayerBase() = default;

        /** Plays the audio */
        virtual void play() = 0;
};