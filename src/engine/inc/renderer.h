#pragma once

#include "vinterface.h"

class Renderer
{
public:
    Renderer();
    ~Renderer();
    
protected:
    VInterface m_interface;
};