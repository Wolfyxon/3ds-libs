#include <3ds.h>
#include <opusfile.h>

class OpusAudioPlayer {
public:
    OpusAudioPlayer();
    ~OpusAudioPlayer();
private:
    OggOpusFile* opusFile;
}