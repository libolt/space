# - Try to find SDL2_Image
# Once done this will define
#
# SDL2_Image_FOUND - system has SDL2_Image
# SDL2_Image_INCLUDE_DIRS - the SDL2_Image include directory
# SDL2_Image_LIBRARIES - the libraries needed to use SDL2_Image
#
# $SDL2_Image_HOME is an environment variable used for finding SDL2_Image.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <


FIND_PATH(SDL2_Image_INCLUDE_DIRS SDL_image.h
    PATHS
    $ENV{SDL2_Image_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES include include/SDL2
    )
IF (WIN32)
FIND_LIBRARY(SDL2_Image_LIBRARIES_REL
    NAMES sdl2_image libSDL2_image.a
    PATHS
    $ENV{SDL2_Image_HOME}/lib/Release
    $ENV{SDL2_Image_HOME}/lib
    /usr/local
    /usr
    )

FIND_LIBRARY(SDL2_Image_LIBRARIES_DBG
    NAMES sdl2_Image_Debug sdl2_Image libsdl2_Image.a
    PATHS
    $ENV{SDL2_Image_HOME}/lib/Debug
    $ENV{SDL2_Image_HOME}/lib
    /usr/local
    /usr
    )
ELSE (WIN32)
FIND_LIBRARY(SDL2_Image_LIBRARY
    NAMES SDL2_Image sdl2_Image libSDL2_image.so libSDL2_Image.a libSDL2_image
    PATHS
    $ENV{SDL2_Image_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES lib64 lib
    )
ENDIF (WIN32)
message (SDL2_Image_LIBRARIES = ${SDL2_Image_LIBRARIES})

# handle the QUIETLY and REQUIRED arguments and set SDL2_Image_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
IF (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_Image DEFAULT_MSG SDL2_Image_LIBRARIES_REL SDL2_Image_LIBRARIES_DBG SDL2_Image_INCLUDE_DIRS)
ELSE (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_Image DEFAULT_MSG SDL2_Image_LIBRARY SDL2_Image_INCLUDE_DIRS)
ENDIF (WIN32)
IF (SDL2_Image_FOUND)
    IF (WIN32)
        SET(SDL2_Image_LIBRARIES optimized ${SDL2_Image_LIBRARIES_REL} debug ${SDL2_Image_LIBRARIES_DBG})
    ELSE (WIN32)
        SET (SDL2_Image_LIBRARIES ${SDL2_Image_LIBRARY})
    ENDIF (WIN32)
ELSE (SDL2_Image_FOUND)
    MESSAGE("SDL2_Image Not Found!")
ENDIF (SDL2_Image_FOUND)

message (SDL2_Image_LIBRARIES = ${SDL2_Image_LIBRARIES})
MARK_AS_ADVANCED(SDL2_Image_LIBRARY SDL2_Image_LIBRARIES SDL2_Image_INCLUDE_DIRS)

