#ifndef _COMMANDLINE_H_
#define _COMMANDLINE_H_

#include "utilities/enums.h"

class commandLine
{
    public:
        commandLine();  // constructor
        ~commandLine();  // destructor

        void parseCommandLine(int argc, char *argv[]);  // parses command line input.
        void displayHelp(void);  // displays command line help output
    private:
        gameTypes gameType;
};

#endif // COMMANDLINE_H
