include_directories("inc")
set(HEADERS inc/messagequeue.h
			inc/messagequeuemanager.h)
set(SOURCES src/messagequeue.cpp
			)
find_package(glfw3 3.2 REQUIRED)
add_library(thread ${HEADERS} ${SOURCES})



