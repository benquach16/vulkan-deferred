#include "vulkandriver.h"
#include <iostream>

VInterface::VInterface() : m_pInstance(0), m_iDeviceCount(0)
{
    init();
}

VInterface::~VInterface()
{
    reset();
}

void VInterface::init()
{
    VkApplicationInfo appInfo;
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;
    
    VkInstanceCreateInfo instanceInfo;
    instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceInfo.pNext = NULL;
    instanceInfo.flags = 0;
    instanceInfo.pApplicationInfo = &appInfo;
    
    
    if(m_pInstance)
    {
        std::cerr << "Attemping to allocate instance again";
    }
    VkResult result = vkCreateInstance(&instanceInfo, 0, m_pInstance);
    
    if(result != VK_SUCCESS)
    {
        std::cerr << "Error on vulkan instance creation : " << result << std::endl;
        exit(0);
    }  
}

void VInterface::getPhysicalDevices()
{
    VkResult result;
    result = vkEnumeratePhysicalDevices(*m_pInstance, &m_iDeviceCount, 0);
    if(result != VK_SUCCESS)
    {
        std::cerr << "Error getting physical devices: " << result << std::endl;
        exit(0);     
    }
    if(!m_iDeviceCount)
    {
        std::cerr << "No vulkan compatible devices detected" << std::endl;
        exit(0);
    }
    if(m_vPhysicalDevices.size() > 0)
    {
        std::cerr << "Physical Devices already allocated" << std::endl;
        exit(0);
    }
    m_vPhysicalDevices.resize(m_iDeviceCount);
    result = vkEnumeratePhysicalDevices(*m_pInstance, &m_iDeviceCount, m_vPhysicalDevices.data());
}

void VInterface::reset()
{
    if(m_pInstance)
        vkDestroyInstance(*m_pInstance, 0);
    m_pInstance = 0;
}
