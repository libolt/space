#ifndef _SOUNDENGINE_H_
#define _SOUNDENGINE_H_

#include "SDL_mixer.h"

#include "utilities/typedefs.h"

class soundEngine
{
    public:
    bool initialize(void);

    private:
    sharedPtr<Mix_Music> music;
    sharedPtr<Mix_Chunk> scratch;
    sharedPtr<Mix_Chunk> high;
    sharedPtr<Mix_Chunk> medium;
    sharedPtr<Mix_Chunk> low;
};

#endif // _SOUNDENGINE_H_
