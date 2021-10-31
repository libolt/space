#include "utilities/commandline.h"

#include <iostream>
#include <string>

commandLine::commandLine()  // constructor
{
    gameType = STANDALONE;
}

commandLine::~commandLine() // destructor
{

}

void commandLine::parseCommandLine(int argc, char *argv[])  // parses command line input.
{
    for (int x=1;x<argc;++x)
    {
        std::string argument(argv[x]);
        std::cout << "argv == " +argument << std::endl;
        if (argument == "-h")
        {
            displayHelp();
        }
        else if (argument == "-s")
        {
            gameType = SERVER;
        }
        else if (argument == "-c")
        {
            gameType = CLIENT;
        }
    }
}

void commandLine::displayHelp(void)  // displays command line help output
{
    std::cout << "Valid arguments to arthurkl are:" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "-s    Starts the game in server mode" << std::endl;
    std::cout << "-c    Starts the game in client mode" << std::endl;
}
