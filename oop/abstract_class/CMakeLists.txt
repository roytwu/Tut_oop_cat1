## set minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

## project name and language
PROJECT(_abstractClass LANGUAGES CXX)

## set source files
SET(SOURCE_FILES main.cpp cat.cpp tiger.cpp)
SET(CMAKE_CXX_STANDARD 14)  #equivalent to adding a flag such as -std=gnu++14


SET(USE_LIBRARY       ON)
SET(BUILD_SHARED_LIBS OFF)
MESSAGE(STATUS "Compile sources into a library?${USE_LIBRARY}$")
LIST(APPEND _sources cat.cpp tiger.cpp)

## Two apporaches:
## 1. Build message.hpp/.cpp into a library, and then linke the resulting library
##    into the executable
## 2. Buld message.hpp/.cpp and cmakeBaisc.cpp into a single executable,
##    without producing the library

IF(USE_LIBRARY)
  ## approach 1:
  ## ADD_LIBRARY will create a static library since BUILD_SHARED_LIBS is OFF
  ADD_LIBRARY(message ${_sources})
  ADD_EXECUTABLE(executable ${SOURCE_FILES})
  TARGET_LINK_LIBRARIES(executable message)
else()
  ## approach 2:
  ADD_EXECUTABLE(executable cmakeBasics.cpp ${_sources})
endif() 
 

 

## add an executable to the project using the specified source files.
#ADD_EXECUTABLE(executable ${SOURCE_FILES})


## tell CMake that the library target has to be linked into the executable target
#TARGET_LINK_LIBRARIES(executable message)
