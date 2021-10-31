#include "engine/graphicsengine.h"

#include <string>

graphicsEngine::graphicsEngine()  // constructor
{

}
graphicsEngine::~graphicsEngine() = default;  // destructor

bool graphicsEngine::initialize()  // initializes the graphics engine
{
    //Initialization flag
    bool success = true;
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() ); success = false;
    }
    else
    {
        //Create window
        sdlWindow = SDL_CreateWindow( "Arthur: King and Legend", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN );
        if( sdlWindow == nullptr )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
/*        else
        {
            //Get window surface
            sdlScreenSurface = SDL_GetWindowSurface( sdlWindow );
        }
*/
        else
        {
            //Create renderer for window
            sdlRenderer = SDL_CreateRenderer( sdlWindow, -1, SDL_RENDERER_ACCELERATED );
            if( sdlRenderer == nullptr )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }
    return success;
}

bool graphicsEngine::loadMedia(std::string path)
{
    //Loading success flag
    bool success = true;
    //Load splash image
/*    SDL_RWops *rwop;
    rwop=SDL_RWFromFile(path.c_str(), "rb");
    sdlHelloWorld = IMG_LoadPNG_RW( rwop );
    if( sdlHelloWorld == nullptr )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
        success = false;
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( sdlHelloWorld, sdlScreenSurface->format, 0 );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( sdlHelloWorld );
    }
    */
    //Load PNG texture
    sdlTexture = loadTexture( path );
    if( sdlTexture == nullptr )
    {
        printf( "Failed to load texture image!\n" );
        success = false;
    }

    return success;
}

SDL_Texture* graphicsEngine::loadTexture( std::string path )
{
    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == nullptr )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( sdlRenderer, loadedSurface );
        if( newTexture == nullptr )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}
bool graphicsEngine::updateWindow()  // updates the contents of the windo
{
/*    //Apply the image
    SDL_BlitSurface( optimizedSurface, nullptr, sdlScreenSurface, nullptr );
    //Update the surface
    SDL_UpdateWindowSurface( sdlWindow );
*/
    //Clear screen
    SDL_RenderClear( sdlRenderer );

    //Render texture to screen
    SDL_RenderCopy( sdlRenderer, sdlTexture, nullptr, nullptr );

    //Update screen
    SDL_RenderPresent( sdlRenderer );

    //Wait two seconds
//    SDL_Delay( 2000 );

    return (true);
}
void graphicsEngine::close()
{
    //Deallocate surface
    SDL_FreeSurface( optimizedSurface );
    optimizedSurface = nullptr;
    //Free loaded image
    SDL_DestroyTexture( sdlTexture );
    sdlTexture = nullptr;

    //Destroy window
    SDL_DestroyRenderer( sdlRenderer );
    sdlRenderer = nullptr;
    //Destroy window
    SDL_DestroyWindow( sdlWindow );
    sdlWindow = nullptr;
    //Quit SDL subsystems
    SDL_Quit();
}

