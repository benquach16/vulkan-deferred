add_subdirectory("app")
#find relevant libraries and link them
set(SOURCES main.cpp)
add_executable (vulkan-deferred ${SOURCES})
find_package(glfw3 3.2 REQUIRED)
target_link_libraries(vulkan-deferred glfw)
target_link_libraries(vulkan-deferred app)
