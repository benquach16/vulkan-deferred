cmake_minimum_required(VERSION 3.7)
project(vulkan)
set(ROOT_DIRECTORY ./)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
#add_subdirectory("inc")
#add_subdirectory("src")

#find relevant libraries and link them


set(SOURCES src/main.cpp)
add_executable (vulkan-deferred ${SOURCES})
find_package(glfw3 3.2 REQUIRED)
target_link_libraries(vulkan-deferred glfw)
