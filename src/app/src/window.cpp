#include "window.h"

Window::Window()
{
    glfwInit();
    m_window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::run()
{
    
}