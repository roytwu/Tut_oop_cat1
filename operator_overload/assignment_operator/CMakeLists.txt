## set minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

## project name and language
PROJECT(_overload LANGUAGES CXX)

## set source files
SET(SOURCE_FILES main.cpp)

## add an executable to the project using the specified source files.
ADD_EXECUTABLE(executable ${SOURCE_FILES})

SET(CMAKE_CXX_STANDARD 14)  #equivalent to adding a flag such as -std=gnu++14
#SET(CMAKE_CXX_EXTENSIONS OFF)
#SET(CMAKE_CXX_STANDARD_REQUIRED ON)


#include(GNUInstallDirs)  ## GNUInstallDirs defines CMAKE_INSTALL_BINDIR
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
#${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}) ## CMAKE_BINARY_DIR is the path to top level of the buid tree


## Print the system name in the CPP code
#TARGET_COMPILE_DEFINITIONS(executable
#	PUBLIC 
#	"SYSTEM_NAME=\"${CMAKE_SYSTEM_NAME}\""
#)

#install(
# TARGETS hello-world
# DESTINATION  ${CMAKE_INSTALL_DINDIR}
#)


