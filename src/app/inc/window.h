#pragma once
#include <GLFW/glfw3.h>
#include "renderer.h"

class Window
{
public:
	Window();
	~Window();
    
    void run();
protected:
    GLFWwindow* m_window;
};
