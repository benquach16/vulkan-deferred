cmake_minimum_required(VERSION 3.7)
project(vulkan)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY build)
#add_subdirectory("inc")
#add_subdirectory("src")
set(SOURCES src/main.cpp)
add_executable (vulkan-deferred ${SOURCES})

