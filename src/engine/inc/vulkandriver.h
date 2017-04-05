#pragma once

#include <vulkan/vulkan.h>
#include <vector>

class VulkanDriver
{
public:
    VulkanDriver();
    ~VulkanDriver();
    
    void init();
    void getPhysicalDevices();
    void reset();
    
    
private:
    uint32_t m_iDeviceCount;
    std::vector<VkPhysicalDevice> m_vPhysicalDevices;
    VkInstance *m_pInstance;
};