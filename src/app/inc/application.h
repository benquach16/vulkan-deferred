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
    std::vector<std::thread> m_views;
    std::thread::id m_currentThreadId;
    bool m_exit = false;
};
