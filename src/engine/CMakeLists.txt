include_directories("inc")
set(HEADERS inc/renderer.h
			inc/vulkandriver.h)
set(SOURCES src/renderer.cpp
			src/vulkandriver.cpp)
find_package(glfw3 3.2 REQUIRED)
add_library(engine ${HEADERS} ${SOURCES})
target_link_libraries(engine glfw)



