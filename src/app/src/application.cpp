#include "application.h"

Application::Application()
{
    //create window on new thread
    m_views.push_back(std::thread([]()
    {
        Window *window = new Window;
        
    }));
    m_currentThreadId = std::this_thread::get_id();
}

Application::~Application()
{
    //cleanup signal to threads that we want to exit
    for(auto i : m_views)
    {
        i.join();
    }
}

void Application::run()
{

}

void Application::processEvents()
{

}
