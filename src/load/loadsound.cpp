#include <load/loadsound.h>
#include "SDL_mixer.h"
#include "SDL.h"
#include <string>
#include <iostream>

bool loadSound::loadMusic(const std::string &file, sharedPtr<Mix_Music*> &music)
{
    Mix_Music **tempMusic = new Mix_Music*[1];
    std::shared_ptr<Mix_Music*> tmpMusic(new Mix_Music*[1]);
    std::cout << "File: " << file << std::endl;

    tempMusic[0] = Mix_LoadMUS(file.c_str());

    tmpMusic.reset(tempMusic);

    music = tmpMusic;
//    music =  std::make_shared<Mix_Music>(Mix_LoadMUS( file.c_str() ));
    if( tempMusic == nullptr )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        return (false);
    }

    return (true);
}

bool loadSFX(const std::string &file, sharedPtr<Mix_Chunk> sfx)
{

    //Load sound effects
    sfx = sharedPtr<Mix_Chunk>(Mix_LoadWAV( file.c_str() ));
    if( sfx == nullptr )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return (false);
    }


    return (true);
}
