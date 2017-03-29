#pragma once

#include <vulkan/vulkan.h>
#include <vector>

class VInterface
{
public:
    VInterface();
    ~VInterface();
    
    void init();
    void getPhysicalDevices();
    void reset();
    
    
private:
    uint32_t m_iDeviceCount;
    std::vector<VkPhysicalDevice> m_vPhysicalDevices;
    VkInstance *m_pInstance;
};