# - Try to find SDL2_Net
# Once done this will define
#
# SDL2_Net_FOUND - system has SDL2_Net
# SDL2_Net_INCLUDE_DIRS - the SDL2_Net include directory
# SDL2_Net_LIBRARIES - the libraries needed to use SDL2_Net
#
# $SDL2_Net_HOME is an environment variable used for finding SDL2_Net.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <

FIND_PATH(SDL2_Net_INCLUDE_DIRS SDL_net.h
    PATHS
    $ENV{SDL2_Net_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES include include/SDL2
    )
IF (WIN32)
FIND_LIBRARY(SDL2_Net_LIBRARIES_REL
    NAMES sdl2_net libSDL2_net.a
    PATHS
    $ENV{SDL2_Net_HOME}/lib/Release
    $ENV{SDL2_Net_HOME}/lib
    /usr/local
    /usr
    )

FIND_LIBRARY(SDL2_Net_LIBRARIES_DBG
    NAMES sdl2_net_Debug sdl2_net libsdl2_net.a
    PATHS
    $ENV{SDL2_Net_HOME}/lib/Debug
    $ENV{SDL2_Net_HOME}/lib
    /usr/local
    /usr
    )
ELSE (WIN32)
FIND_LIBRARY(SDL2_Net_LIBRARY
    NAMES SDL2_net sdl2_net libSDL2_net.a
    PATHS
    $ENV{SDL2_Net_HOME}
    /usr/local
    /usr
    )
ENDIF (WIN32)
# handle the QUIETLY and REQUIRED arguments and set SDL2_Net_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
IF (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_Net DEFAULT_MSG SDL2_Net_LIBRARIES_REL SDL2_Net_LIBRARIES_DBG SDL2_Net_INCLUDE_DIRS)
ELSE (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_Net DEFAULT_MSG SDL2_Net_LIBRARY SDL2_Net_INCLUDE_DIRS)
ENDIF (WIN32)
IF (SDL2_Net_FOUND)
    IF (WIN32)
        SET(SDL2_Net_LIBRARIES optimized ${SDL2_Net_LIBRARIES_REL} debug ${SDL2_Net_LIBRARIES_DBG})
    ELSE (WIN32)
        SET (SDL2_Net_LIBRARIES ${SDL2_Net_LIBRARY})
    ENDIF (WIN32)
ELSE (SDL2_Net_FOUND)
    MESSAGE("SDL2_Net Not Found!")
ENDIF (SDL2_Net_FOUND)

MARK_AS_ADVANCED(SDL2_Net_LIBRARY SDL2_Net_LIBRARIES SDL2_Net_INCLUDE_DIRS)

