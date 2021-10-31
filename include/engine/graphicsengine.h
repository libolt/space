#ifndef _GRAPHICSENGINE_H_
#define _GRAPHICSENGINE_H_

#include "SDL.h"
#include "SDL_image.h"

#include "utilities/typedefs.h"

class graphicsEngine
{
public:
    graphicsEngine();  // constructor
    ~graphicsEngine();  // destructor

    bool initialize();  // initializes the graphics engine
    //Loads media
    bool loadMedia(std::string path);
    //Loads individual image as texture
    SDL_Texture* loadTexture( std::string path );


    bool updateWindow();  // updates the contents of the window
    //Frees media and shuts down SDL
    void close();

private:
    //The window we'll be rendering to
    SDL_Window* sdlWindow = nullptr; //The surface contained by the window
    SDL_Surface* sdlScreenSurface = nullptr;
    //The image we will load and show on the screen
    SDL_Surface* sdlHelloWorld = nullptr;
    //The final optimized image
    SDL_Surface* optimizedSurface = nullptr;
    //The window renderer
    SDL_Renderer* sdlRenderer = nullptr;

    //Current displayed texture
    SDL_Texture* sdlTexture = nullptr;

};

#endif // _GRAPHICSENGINE_H_
