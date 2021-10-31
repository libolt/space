#include "engine/inputengine.h"

inputEngine::inputEngine()  // constructor
{
}
inputEngine::~inputEngine() = default;  // destructor

bool inputEngine::initialize()  // initializes the input engine
{
    return (true);
}

bool inputEngine::processInput()  // proccesses input events
{
    currentKeyStates = SDL_GetKeyboardState( nullptr );
    if( currentKeyStates[ SDL_SCANCODE_UP ] )
    {
        exit(0);
    }

    return (true);
}
