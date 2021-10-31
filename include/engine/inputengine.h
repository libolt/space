#ifndef _INPUTENGINE_H_
#define _INPUTENGINE_H_

#include "SDL.h"

#include "utilities/typedefs.h"

class inputEngine
{
public:
    inputEngine();  // constructor
    ~inputEngine();  // destructor

    bool initialize();  // initializes the input engine
    bool processInput();  // proccesses input events

private:
    const Uint8* currentKeyStates;
};

#endif // _INPUTENGINE_H_
