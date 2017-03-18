#include "application.h"

Application::Application()
{
    m_window = new Window;
}

Application::~Application()
{
    delete m_window;
}

void Application::run()
{
    while(!m_exit)
    {
        m_window->run();
    }
}

void Application::processEvents()
{

}
