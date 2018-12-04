## set minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

## project name and language
PROJECT(cmakeBasics LANGUAGES CXX)

ADD_LIBRARY(message
 STATIC
  message.hpp
  message.cpp
)

## set source files
SET(SOURCE_FILES cmakeBasics.cpp)
SET(CMAKE_CXX_STANDARD 14)  #equivalent to adding a flag such as -std=gnu++14

## add an executable to the project using the specified source files.
ADD_EXECUTABLE(executable ${SOURCE_FILES})


## tell CMake that the library target has to be linked into the executable target
TARGET_LINK_LIBRARIES(executable message)




