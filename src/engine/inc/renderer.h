#pragma once

#include "vulkandriver.h"

class Renderer
{
public:
    Renderer();
    ~Renderer();
    
protected:
    VInterface m_interface;
};
