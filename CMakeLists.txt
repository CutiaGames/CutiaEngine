cmake_minimum_required(VERSION 3.0)
project(game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# A Linux Package is Required
# sudo apt install cmake libsdl2-dev g++

# ENGINE DIR
# Define cmake variables
set (SRC_DIR "${PROJECT_SOURCE_DIR}/engine/src")
set (INCL_DIR "${PROJECT_SOURCE_DIR}/engine/include")
set (LIB_PATH "${PROJECT_SOURCE_DIR}/lib")

# GAMES DIR
# Define cmake variables
set (GAME_SRC_DIR "${PROJECT_SOURCE_DIR}/games/SuperDiscoFighter2000/src")
set (GAME_INCL_DIR "${PROJECT_SOURCE_DIR}/games/SuperDiscoFighter2000/include")
set (MIDI_SRC "${LIB_PATH}/source")


set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_MIXER_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})




# Recursive search for cpp and c files on  project root directory
file(GLOB SRC ${SRC_DIR}/*.cpp 
        ${SRC_DIR}/*.c
        ${GAME_SRC_DIR}/*.cpp
        ${GAME_SRC_DIR}/*.c 
        ${MIDI_SRC}/*.c
        ${MIDI_SRC}/*.cpp
        )


# Adapt flags by compiler id
if (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} -std=c++11 -W -Wall -pedantic -std=c++11 -Wshadow -O2 -g")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} -std=c++11 -W -Wall -pedantic -std=c++11 -Wshadow -O2 -g")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} /Wall")
endif()

# Cmake compilation flags redefinition
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

# Include headers
include_directories("${INCL_DIR}")
include_directories("${GAME_INCL_DIR}")

# manual import of midifile library
include_directories("${LIB_PATH}/include")


# Create engine executable
add_executable(game ${SRC})

target_link_libraries(game
                            ${SDL2_LIBRARY}
                            ${SDL2_IMAGE_LIBRARIES}
                            ${SDL2_MIXER_LIBRARIES}
                            ${SDL2_TTF_LIBRARIES})

