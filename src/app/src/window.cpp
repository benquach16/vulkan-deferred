#include "window.h"

Window::Window() : m_renderer(0)
{
    glfwInit();
    m_window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
    m_renderer = new Renderer();
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::run()
{
    
}