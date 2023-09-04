#include <3ds.h>
#include <opusfile.h>
#include <cstring>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

class OpusAudioPlayer {
public:
    OpusAudioPlayer(int channel_=0);
    ~OpusAudioPlayer();

    int channel = 0;
    OggOpusFile *opusFile = NULL;

    bool load(char* filePath);
    void unload();
    bool play();

private:

};
