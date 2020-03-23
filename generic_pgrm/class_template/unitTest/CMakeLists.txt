#* Use OpenCV without Trunk 
#* History: 
#*   02/08/2019  initial version
#*   02/26/2019  adding Eigen library
#*   03/13/2020  adding Boost library
#*   03/21/2020  Boost was accessed by Visual Studio
 
#* set minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

#* project name and language
PROJECT(_testTemplate LANGUAGES CXX)

#*Read environment variable to custom name
SET(BOOST            $ENV{BOOST_INCLUDEDIR})

INCLUDE_DIRECTORIES(
  ${OpenCV_INCLUDE_DIRS} #* defined by OpenCV in OpenCVConfig.cmake 
  ${EIGEN}/include/eigen3/
  ${BOOST}
)

#* set source files
SET(SOURCE_FILES 
  test_main.cpp
  #../account.cpp  #* test target
)

SET(CMAKE_CXX_STANDARD 14)  #equivalent to adding a flag such as -std=gnu++14
SET(USE_LIBRARY       ON)
SET(BUILD_SHARED_LIBS OFF)

#ADD_LIBRARY(message
# STATIC #option: STATIC or SHARED
#  message.hpp
#)


#* add an executable to the project using the specified source files.
ADD_EXECUTABLE(executable 
  ${SOURCE_FILES}
)

#* tell CMake that the library target has to be linked into the executable target
TARGET_LINK_LIBRARIES(executable
#  ${OpenCV_LIBS}
)
