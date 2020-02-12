#* Use OpenCV without Trunk 
#* History: 
#*   02/27/2019  initial version
 
#* set minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

#* project name and language
PROJECT(_quat LANGUAGES CXX)

FIND_PACKAGE(OpenCV REQUIRED)

#*Read environment variable to custom name
SET(OpenCV_DIR       $ENV{OpenCV_DIR})
SET(EIGEN            $ENV{EIGEN_DIR})

INCLUDE_DIRECTORIES(
  ${OpenCV_INCLUDE_DIRS} #* defined by OpenCV in OpenCVConfig.cmake 
  ${EIGEN}/include/eigen3/
)

#* set source files
SET(SOURCE_FILES 
  main.cpp
  mapping.cpp
  quaternion.cpp
)

SET(CMAKE_CXX_STANDARD 14)  #equivalent to adding a flag such as -std=gnu++14
SET(USE_LIBRARY       ON)
SET(BUILD_SHARED_LIBS OFF)

#ADD_LIBRARY(message
# STATIC #option: STATIC or SHARED
#  message.hpp
#  message.cpp
#)


#* add an executable to the project using the specified source files.
ADD_EXECUTABLE(executable 
  ${SOURCE_FILES}
)

#* tell CMake that the library target has to be linked into the executable target
TARGET_LINK_LIBRARIES(executable
  ${OpenCV_LIBS}
)
