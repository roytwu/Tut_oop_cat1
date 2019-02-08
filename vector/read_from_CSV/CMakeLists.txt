#* Latest update: 02/08/2019
#* set minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

#* project name and language
PROJECT(_readCSV LANGUAGES CXX)


#* Required by the CMAKE 3.12 and up
IF (POLICY CMP0074)
  CMAKE_POLICY(SET CMP0074 NEW)  # BOOST_ROOT
ENDIF()

FIND_PACKAGE(OpenCV REQUIRED)
FIND_PACKAGE(Boost COMPONENTS system chrono filesystem thread locale REQUIRED)
if(Boost_FOUND)
    message(STATUS "Success to find Boost!")
endif()

#* Read environment variable to custom name
SET(OpenCV_DIR        $ENV{OPENCV_DIR})
SET(BOOST_INCLUDEDIR  $ENV{BOOST_INCLUDEDIR})
SET(BOOST_ROOT        $ENV{BOOST_ROOT})


INCLUDE_DIRECTORIES(
  ${OpenCV_INCLUDE_DIRS}  #*defined by OpenCV in OpenCVConfig.cmake 
  ${Boost_INCLUDE_DIRS}
)


SET(CMAKE_CXX_STANDARD 14)  #*equivalent to adding a flag such as -std=gnu++14
#SET(USE_LIBRARY       ON)
#SET(BUILD_SHARED_LIBS OFF)


#* Common pre-installed libraries
SET(LIBS
  ${LIBS}
  ${OpenCV_LIBS} #*OpenCV Libraries
  ${Boost_THREAD_LIBRARY} #*Boost Libraries
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_CHRONO_LIBRARY}
  ${Boost_MATH_LIBRARY}
  ${Boost_NUMERIC_LIBRARY}
  ${Boost_ACCUMULATORS_LIBRARY}
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_REGEX_LIBRARY}
  ${Boost_LOCALE_LIBRARY}
)

#* Directories to search for pre-installed library components.
LINK_DIRECTORIES(
  ${Boost_LIBRARY_DIRS}
)


#* set source files
SET(SOURCE_FILES 
  main.cpp 
  imuData.cpp 
  readCSV.cpp
)

#* add an executable to the project using the specified source files.
ADD_EXECUTABLE(executable ${SOURCE_FILES})


#* tell CMake that the library target has to be linked into the executable target
TARGET_LINK_LIBRARIES(executable 
  ${OpenCV_LIBS}  #*defined by OpenCV in OpenCVConfig.cmake 
  ${Boost_LIBS}
)
