#* Use OpenCV without Trunk 
#* History: 
#*   02/27/2019  initial version
#*   04/10/2019  adding VTK  
 
#* set minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

#* project name and language
PROJECT(_cubic LANGUAGES CXX)

FIND_PACKAGE(OpenCV REQUIRED)
FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

#*Read environment variable to custom name
SET(OpenCV_DIR       $ENV{OpenCV_DIR})
SET(EIGEN            $ENV{EIGEN_DIR})
SET(VTK_DIR          $ENV{VTK_DIR})

INCLUDE_DIRECTORIES(
  ${OpenCV_INCLUDE_DIRS} #* defined by OpenCV in OpenCVConfig.cmake 
  ${EIGEN}/include/eigen3/
)

#* set libraries
#SET(LIBS
#  ${LIBS}
#  ${VTK_LIBRARIES}
#)

#* set source files
SET(SOURCE_FILES 
  main.cpp
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
  ${VTK_LIBRARIES}
)
