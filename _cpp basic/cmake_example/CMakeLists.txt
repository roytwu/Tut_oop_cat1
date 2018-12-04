## set minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

## project name and language
PROJECT(cmakeBasics LANGUAGES CXX)

## set source files
SET(SOURCE_FILES cmakeBasics.cpp)

## add an executable to the project using the specified source files.
ADD_EXECUTABLE(executable ${SOURCE_FILES})

SET(CMAKE_CXX_STANDARD 14)  #equivalent to adding a flag such as -std=gnu++14
#SET(CMAKE_CXX_EXTENSIONS OFF)
#SET(CMAKE_CXX_STANDARD_REQUIRED ON)




