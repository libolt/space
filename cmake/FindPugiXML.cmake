# - Try to find PugiXML
# Once done this will define
#
# PugiXML_FOUND - system has PugiXML
# PugiXML_INCLUDE_DIRS - the PugiXML include directory
# PugiXML_LIBRARIES - the libraries needed to use PugiXML
#
# $PugiXML_HOME is an environment variable used for finding PugiXML.
#
# Borrowed from The Mana World
# http://themanaworld.org/
#
# Several changes and additions by Fabian 'x3n' Landau
# Lots of simplifications by Adrian Friedli
# > www.orxonox.net <


FIND_PATH(PugiXML_INCLUDE_DIR pugixml.hpp
    PATHS
    $ENV{PugiXML_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES include include
    )
IF (WIN32)
FIND_LIBRARY(PugiXML_LIBRARIES_REL
    NAMES pugixml libpugixml.a
    PATHS
    $ENV{PugiXML_HOME}/lib/Release
    $ENV{PugiXML_HOME}/lib
    /usr/local
    /usr
    )

FIND_LIBRARY(PugiXML_LIBRARIES_DBG
    NAMES pugixml_Debug pugixml libpugixml.a
    PATHS
    $ENV{PugiXML_HOME}/lib/Debug
    $ENV{PugiXML_HOME}/lib
    /usr/local
    /usr
    )
ELSE (WIN32)
FIND_LIBRARY(PugiXML_LIBRARY
    NAMES PugiXML pugixml libpugixml.so libPugiXML.a
    PATHS
    $ENV{PugiXML_HOME}
    /usr/local
    /usr
    PATH_SUFFIXES lib64 lib
    )
ENDIF (WIN32)
message (PugiXML_LIBRARIES = ${PugiXML_LIBRARIES})

# handle the QUIETLY and REQUIRED arguments and set PugiXML_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE(FindPackageHandleStandardArgs)
IF (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(PugiXML DEFAULT_MSG PugiXML_LIBRARIES_REL PugiXML_LIBRARIES_DBG PugiXML_INCLUDE_DIR)
ELSE (WIN32)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(PugiXML DEFAULT_MSG PugiXML_LIBRARY PugiXML_INCLUDE_DIR)
ENDIF (WIN32)
IF (PugiXML_FOUND)
    IF (WIN32)
        SET(PugiXML_LIBRARIES optimized ${PugiXML_LIBRARIES_REL} debug ${PugiXML_LIBRARIES_DBG})
    ELSE (WIN32)
        SET (PugiXML_LIBRARIES ${PugiXML_LIBRARY})
    ENDIF (WIN32)
ELSE (PugiXML_FOUND)
    MESSAGE("PugiXML Not Found!")
ENDIF (PugiXML_FOUND)

message (PugiXML_LIBRARIES = ${PugiXML_LIBRARIES})
MARK_AS_ADVANCED(PugiXML_LIBRARY PugiXML_LIBRARIES PugiXML_INCLUDE_DIR)

