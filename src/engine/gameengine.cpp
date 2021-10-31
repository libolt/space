#include "engine/gameengine.h"
#include "engine/graphicsengine.h"
#include "engine/inputengine.h"
#include "engine/networkengine.h"
#include "engine/soundengine.h"
#include "load/loadsound.h"

#include <string>
#include <iostream>

gameEngine::gameEngine()  // constructor
{
    quitGame = false;
    graphicsEInitialized = false;
    inputEInitialized = false;
    networkEInitialized = false;
    soundEInitialized = false;
    titleLoaded = false;
}
gameEngine::~gameEngine() = default;;  // destructor


sharedPtr<graphicsEngine> gameEngine::getGraphicsE() const  // retrieves the value of graphicsE
{
    return (graphicsE);
}
void gameEngine::setGraphicsE(const sharedPtr<graphicsEngine> &set)  // sets the value of graphicsE
{
    graphicsE = set;
}


sharedPtr<inputEngine> gameEngine::getInputE() const  // retrieves the value of inputE
{
    return (inputE);
}
void gameEngine::setInputE(const sharedPtr<inputEngine> &set)  // sets the value of inputE
{
    inputE = set;
}

sharedPtr<networkEngine> gameEngine::getNetworkE() const  // retrieves the value of networkE
{
    return (networkE);
}
void gameEngine::setNetworkE(const sharedPtr<networkEngine> &set)  // sets the value of networkE
{
    networkE = set;
}

sharedPtr<soundEngine> gameEngine::getSoundE() const  // retrieves the value of soundE
{
    return (soundE);
}
void gameEngine::setSoundE(const sharedPtr<soundEngine> &set)  // sets the value of soundE
{
    soundE = set;
}

bool gameEngine::getQuitGame() const  // retrieves the value of quitGame
{
    return (quitGame);
}
void gameEngine::setQuitGame(const bool &set)  // sets the value of quitGame
{
    quitGame = set;
}

bool gameEngine::getGraphicsEInitialized() const  // retrieves the value of graphicsEInitialized
{
    return (graphicsEInitialized);
}
void gameEngine::setGraphicxEInitialized(const bool &set)  // sets the value of graphicsEInitialied
{
    graphicsEInitialized = set;
}

bool gameEngine::getInputEInitialized() const  // retrieves the value of inputEInitialized
{
    return (inputEInitialized);
}
void gameEngine::setInputEInitialized(const bool &set)  // sets the value of inputEInitialized
{
    inputEInitialized = set;
}

bool gameEngine::getNetworkEInitialized() const  // retrieves the value of networkEInitialized
{
    return (networkEInitialized);
}
void gameEngine::setNetworkEInitialized(const bool &set)  // sets the value of networkEInitialized
{
    networkEInitialized = set;
}

bool gameEngine::getSoundEInitialized() const  // retrieves the value of soundEInitialized
{
    return (soundEInitialized);
}
void gameEngine::setSoundEInitialized(const bool &set)  // sets the value of soundEInitialized
{
    soundEInitialized = set;
}

bool gameEngine::getTitleLoaded() const  // retrieves the value of titleLoaded
{
    return (titleLoaded);
}
void gameEngine::setTitleLoaded(const bool &set)  // sets the value of titleLoaded
{
    titleLoaded = false;
}

gameTypes gameEngine::getGameType() const  // retrieves the value of gameType
{
    return (gameType);
}
void gameEngine::setGameType(const gameTypes &set)  // sets the value of gameType
{
    gameType = set;
}


bool gameEngine::initialize()  // initializes the game engine
{
   sharedPtr<graphicsEngine> tempGraphicsE(new graphicsEngine);
   graphicsE = tempGraphicsE;

   sharedPtr<inputEngine> tempInputE(new inputEngine);
   inputE = tempInputE;

   sharedPtr<networkEngine> tempNetworkE(new networkEngine);
   networkE = tempNetworkE;

   sharedPtr<soundEngine> tempSoundE(new soundEngine);
   soundE = tempSoundE;

   sharedPtr<loadSound> loadS(new loadSound);

    // Initializes Graphics Engine
    if (!graphicsEInitialized)
    {
        if( !graphicsE->initialize() )
        {
            std::cout << "Failed to initialize Graphics Engine!" << std::endl;
        }
        else
        {
            graphicsEInitialized = true;
        }
    }
    else
    {

    }

    // Initializes Input Engine
    if (!inputEInitialized)
    {
        if( !inputE->initialize() )
        {
            std::cout << "Failed to initialize!\n" << std::endl;
        }
        else
        {
            inputEInitialized = true;
        }
    }
    else
    {

    }

    // Initializes Network Engine
    if (!networkEInitialized)
    {
        if( !networkE->initialize() )
        {
            std::cout << "Failed to initialize!\n" << std::endl;
        }
        else
        {
            networkEInitialized = true;
        }
    }
    else
    {

    }

    // Initializes Sound Engine
    if (!soundEInitialized)
    {
        if( !soundE->initialize() )
        {
            std::cout << "Failed to initialize!\n" << std::endl;
        }
        else
        {
            soundEInitialized = true;
        }
    }
    else
    {

    }

    loadTitle();
    loadS->loadMusic("data/media/music/alexander-nakarada-we-three-celtic-kings.mp3", music);
    playTitleMusic();
    return(true);
}

bool gameEngine::loadTitle()  // loads the title screen
{
    //Load media
    if (!titleLoaded)
    {
        std::string title = "data/images/King-Arthur-Logo.png";

        if( !graphicsE->loadMedia(title.c_str()) )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            titleLoaded = true;
        }
    }
    return (true);
}

bool gameEngine::loop()  // loops through game engine logic
{
    //Handle events on queue
    while( SDL_PollEvent( &event ) != 0 )
    {
        //User requests quit
        if( event.type == SDL_QUIT )
        {
            quitGame = true;
        }
    }
    return (true);
}

bool gameEngine::playTitleMusic()
{
    if (Mix_PlayMusic(music.get()[0], -1) == -1)
    {
        printf("Mix_PlayMusic: %s\n", Mix_GetError());
        // well, there's no music, but most games don't break without music...
    }

    return (true);
}
