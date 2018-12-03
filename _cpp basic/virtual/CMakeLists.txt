# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(virtual LANGUAGES CXX)

#define executable and its source file
add_executable(hello-world virtual.cpp)

include(GNUInstallDirs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

target_compile_definitions(
	PUBLIC 
	"TEST_TEST_123 = \"${CMAKE_SYSTEM_NAME}\""
)

install(
 TARGETS
 hello-world
 DESTINATION 
 ${CMAKE_INSTALL_BINDIR}
)


