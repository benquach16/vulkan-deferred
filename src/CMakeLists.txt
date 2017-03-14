add_subdirectory("app")

set(SOURCES main.cpp)
list(APPEND CMAKE_CXX_FLAGS "-pthread -std=c++14")
add_executable (vulkan-deferred ${SOURCES})
find_package(glfw3 3.2 REQUIRED)
target_link_libraries(vulkan-deferred glfw)
target_link_libraries(vulkan-deferred app)
