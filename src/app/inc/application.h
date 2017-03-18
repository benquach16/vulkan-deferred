#pragma once
#include "window.h"
#include <thread>
#include <vector>

class Application
{
public:
    
	Application();
    ~Application();
    
    void run();
    void processEvents();
protected:
    Window *m_window;
    bool m_exit = false;
};
