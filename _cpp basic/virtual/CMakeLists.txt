## set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

## project name and language
project(virtual LANGUAGES CXX)

## define executable and its source file
add_executable(executableFile virtual.cpp)

#set(CMAKE_CXX_STANDARD 14)  #equivalent to adding a flag such as -std=gnu++14
#set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)


#include(GNUInstallDirs)  ## GNUInstallDirs defines CMAKE_INSTALL_BINDIR
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
#${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}) ## CMAKE_BINARY_DIR is the path to top level of the buid tree



# Print the system name in the CPP code
target_compile_definitions(executableFile
	PUBLIC 
	"SYSTEM_NAME=\"${CMAKE_SYSTEM_NAME}\""
)

#install(
# TARGETS hello-world
# DESTINATION  ${CMAKE_INSTALL_DINDIR}
#)


