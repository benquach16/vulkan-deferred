include_directories("inc")
set(HEADERS inc/window.h
			inc/application.h)
set(SOURCES src/window.cpp
			src/application.cpp)
find_package(glfw3 3.2 REQUIRED)
add_library(app ${HEADERS} ${SOURCES})
target_link_libraries(app glfw)


