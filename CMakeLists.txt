cmake_minimum_required(VERSION 3.0)
project(CutiaEngine)

# A Linux Package is Required
# sudo apt install cmake libsdl2-dev g++

# Define cmake variables
set (SRC_DIR "${PROJECT_SOURCE_DIR}/engine/src")
set (INCL_DIR "${PROJECT_SOURCE_DIR}/engine/include")
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR})


# Recursive search for cpp and c files on source directory
file(GLOB SRC ${SRC_DIR}/*.cpp)


# Adapt flags by compiler id
if (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} -std=c++11 -W -Wall -pedantic -std=c++11 -Wshadow -O2 -g")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} -std=c++11 -W -Wall -pedantic -std=c++11 -Wshadow -O2 -g")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set(COMPILE_FLAGS "${COMPILE_FLAGS} /Wall")
endif()

# Cmake compilation flags redefinition
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")


# Include headers
include_directories("${INCL_DIR}")


# Create engine executable
add_executable(CutiaEngine ${SRC})

target_link_libraries(CutiaEngine ${SDL2_LIBRARY}
                             ${SDL2_IMAGE_LIBRARIES}
                             ${SDL2_TTF_LIBRARIES})
