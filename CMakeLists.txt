cmake_minimum_required(VERSION 2.8)

project(space)
SET(CMAKE_MODULE_PATH "${space_SOURCE_DIR}/cmake")
find_package (SDL2)
find_package(SDL2_Image)
find_package (SDL2_Mixer)
find_package(SDL2_Net)
find_package(PugiXML)
message(SDL2_INClUDE DIR = ${SDL2_INCLUDE_DIR})

SET (space_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${space_INCLUDE_DIR} ${SDL2_INCLUDE_DIR} ${SDL2_Image_INCLUDE_DIRS} ${SDL2_Mixer_INCLUDE_DIRS} ${SDL2_Net_INCLUDE_DIRS} ${PugiXML_INCLUDE_DIR})
LINK_DIRECTORIES()
message (SDL2_LIBRARY = ${SDL2_LIBRARY})
message (SDL2_Image_LIBRARIES = ${SDL2_Image_LIBRARIES})
message (PUGIXML_INCLUDE_DIR = ${PugiXML_INCLUDE_DIR})

FILE(GLOB_RECURSE space_HEADERS include/*.h)
FILE(GLOB_RECURSE space_SRCS src/*.cpp)

add_executable(${PROJECT_NAME} ${space_SRCS} ${space_HEADERS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_Image_LIBRARIES} ${SDL2_Mixer_LIBRARIES} ${SDL2_Net_LIBRARIES} ${PugiXML_LIBRARIES})


add_custom_command(
        TARGET space POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/data
                ${CMAKE_CURRENT_BINARY_DIR}/data)
