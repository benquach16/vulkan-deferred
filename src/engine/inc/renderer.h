#pragma once

#include "vulkandriver.h"
#include <GLFW/glfw3.h>

class Renderer
{
public:
    Renderer();
    ~Renderer();
    void initializeRenderer(GLFWwindow *window);
protected:
    VulkanDriver m_driver;
};
