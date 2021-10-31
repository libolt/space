#ifndef _LOADSOUND_H_
#define _LOADSOUND_H_

#include "SDL_mixer.h"

#include "utilities/typedefs.h"

class loadSound
{
    public:
    bool loadMusic(const std::string &file, sharedPtr<Mix_Music*> &music);
    bool loadSFX(const std::string &file, sharedPtr<Mix_Chunk> sfx);
    private:
};

#endif // _LOADSOUND_H_
