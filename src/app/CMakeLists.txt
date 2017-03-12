include_directories("inc")
set(HEADERS inc/window.h
			inc/application.h)
set(SOURCES src/window.cpp
			src/application.cpp)

add_library(app ${HEADERS} ${SOURCES})


