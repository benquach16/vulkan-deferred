cmake_minimum_required(VERSION 3.7)
project(vulkan)
set(BASEPATH "${CMAKE_SOURCE_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
include_directories("src")
#add_subdirectory("inc")
add_subdirectory("src")


