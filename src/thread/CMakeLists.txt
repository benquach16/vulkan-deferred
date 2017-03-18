include_directories("inc")
set(HEADERS inc/renderer.h
			inc/vinterface.h)
set(SOURCES src/renderer.cpp
			src/vinterface.cpp)
find_package(glfw3 3.2 REQUIRED)
add_library(thread ${HEADERS} ${SOURCES})
target_link_libraries(engine glfw)


