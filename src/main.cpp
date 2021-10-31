#include "main.h"

#include "engine/gameengine.h"
#include "engine/graphicsengine.h"
#include "engine/inputengine.h"
#include "utilities/commandline.h"

#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
    sharedPtr<commandLine> cmdLine(new commandLine);
    sharedPtr<gameEngine> gameE(new gameEngine);

    if (argc > 1)
    {
        cmdLine->parseCommandLine(argc, argv);
    }
    //Start up the gameEngine
    if( !gameE->initialize() )
    {
        printf( "Failed to initialize!\n" );
    }
    gameE->getGraphicsE()->updateWindow();

    while (!gameE->getQuitGame())
    {
        std::cout << "blah" << endl;
        gameE->loop();
        gameE->getInputE()->processInput();
    }

    //Free resources and close SDL
    gameE->getGraphicsE()->close();

    return 0;
}
