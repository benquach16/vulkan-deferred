#include "vulkandriver.h"
#include <iostream>

VulkanDriver::VulkanDriver() : m_pInstance(0), m_iDeviceCount(0)
{
    init();
}

VulkanDriver::~VulkanDriver()
{
    reset();
}

void VulkanDriver::init()
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
    
    getPhysicalDevices();
}

void VulkanDriver::getPhysicalDevices()
{
    
    //query and enumerate vulkan queues
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
    if(result != VK_SUCCESS)
    {
        //some error on getting physical devices
    }
    
    VkPhysicalDeviceProperties deviceProperties;
    for (uint32_t i = 0; i < m_iDeviceCount; i++) {
        vkGetPhysicalDeviceProperties(m_vPhysicalDevices[i], &deviceProperties);
        printf("Driver Version: %d\n", deviceProperties.driverVersion);
        printf("Device Name:    %s\n", deviceProperties.deviceName);
        printf("Device Type:    %d\n", deviceProperties.deviceType);
        printf("API Version:    %d.%d.%d\n",
            // See note below regarding this:
            (deviceProperties.apiVersion>>22)&0x3FF,
            (deviceProperties.apiVersion>>12)&0x3FF,
            (deviceProperties.apiVersion&0xFFF));
    }
    
    for(int i = 0; i < m_iDeviceCount; ++i)
    {
        
    }
    
}

void VulkanDriver::reset()
{
    if(m_pInstance)
        vkDestroyInstance(*m_pInstance, 0);
    m_pInstance = 0;
}
