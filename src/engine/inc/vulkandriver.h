#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <GLFW/glfw3.h>

struct SwapChain
{
    VkImage image;
};

class VulkanDriver
{
public:
    VulkanDriver();
    ~VulkanDriver();
    
    void initializeDriver(GLFWwindow* window);
    void init();
    void getPhysicalDevices();
    void reset();
    
    
private:
    uint32_t m_iDeviceCount;
    std::vector<VkPhysicalDevice> m_vPhysicalDevices;
    VkInstance *m_pInstance;
};