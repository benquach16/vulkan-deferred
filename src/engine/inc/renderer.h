#pragma once

#include "vulkandriver.h"

class Renderer
{
public:
    Renderer();
    ~Renderer();
    
protected:
    VulkanDriver m_driver;
};
