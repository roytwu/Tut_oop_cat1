## set minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

## project name and language
PROJECT(_openCVDemo LANGUAGES CXX)

## set source files
SET(SOURCE_FILES main.cpp)
SET(CMAKE_CXX_STANDARD 14)  #equivalent to adding a flag such as -std=gnu++14


SET(USE_LIBRARY       ON)
SET(BUILD_SHARED_LIBS OFF)



ADD_EXECUTABLE(executable main.cpp ${_sources})

 
#ADD_LIBRARY(message
# STATIC #option: STATIC or SHARED
#  message.hpp
#  message.cpp
#)


## add an executable to the project using the specified source files.
#ADD_EXECUTABLE(executable ${SOURCE_FILES})


## tell CMake that the library target has to be linked into the executable target
#TARGET_LINK_LIBRARIES(executable message)
