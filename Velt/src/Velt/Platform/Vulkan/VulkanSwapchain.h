#pragma once
#include "vtpch.h"
#include "VulkanDevice.h"
#include "Velt/Renderer/Swapchain.h"
#include "Velt/Renderer/Framebuffer.h"
#include "Velt/Renderer/RenderPass.h"

namespace Velt::Renderer::Vulkan {

    class VELT_API VulkanSwapchain : public Swapchain
    {
    public:
        static constexpr int MAX_FRAMES_IN_FLIGHT = 3;

        VulkanSwapchain(VulkanDevice& deviceRef, VkExtent2D windowExtent);
        VulkanSwapchain(VulkanDevice& deviceRef, VkExtent2D windowExtent, VulkanSwapchain* previous);
        ~VulkanSwapchain();

        VulkanSwapchain(const VulkanSwapchain&) = delete;
        void operator=(const VulkanSwapchain&) = delete;

        virtual Framebuffer* GetFramebuffer(int index) override { return reinterpret_cast<void*>(getFrameBuffer(index)); }
        virtual Renderpass* GetRenderPass() override { return reinterpret_cast<void*>(getRenderPass()); }
        virtual void* GetImageView(int index) override { return reinterpret_cast<void*>(getImageView(index)); }
        // virtual size_t GetImageCount() const override { return swapChainImages.size(); }
        virtual u32 GetWidth() const override { return swapChainExtent.width; }
        virtual u32 GetHeight() const override { return swapChainExtent.height; }
        virtual float GetAspectRatio() const override { return static_cast<float>(swapChainExtent.width) / static_cast<float>(swapChainExtent.height); }
        virtual int AcquireNextImage(u32& imageIndex) override { return static_cast<int>(acquireNextImage(imageIndex)); }
        virtual int SubmitCommandBuffers(const void* buffers, u32* imageIndex) override { return static_cast<int>(submitCommandBuffers(reinterpret_cast<const VkCommandBuffer*>(buffers), imageIndex)); }

        Framebuffer getFrameBuffer(int index) { return swapChainFramebuffers[index]; }
        Renderpass getRenderPass() { return renderPass; }
        VkImageView getImageView(int index) { return swapChainImageViews[index]; }
        size_t imageCount() { return swapChainImages.size(); }
        VkFormat getVulkanSwapchainImageFormat() { return swapChainImageFormat; }
        VkExtent2D getVulkanSwapchainExtent() { return swapChainExtent; }
        u32 width() { return swapChainExtent.width; }
        u32 height() { return swapChainExtent. height; }

        float extentAspectRatio()
        {
            return static_cast<float>(swapChainExtent.width) / static_cast<float>(swapChainExtent.height);
        }
        VkFormat findDepthFormat();

        VkResult acquireNextImage(u32 &imageIndex);
        VkResult submitCommandBuffers(const VkCommandBuffer* buffers, u32* imageIndex);

    private:
        void init();
        void createVulkanSwapchain();
        void createImageViews();
        void createDepthResources();
        void createRenderPass();
        void createFramebuffers();
        void createSyncObjects();

        VkSurfaceFormatKHR chooseSwapSurfaceFormat(
            const std::vector<VkSurfaceFormatKHR>& availableFormats);
        VkPresentModeKHR chooseSwapPresentMode(
            const std::vector<VkPresentModeKHR>& availablePresentModes);
        VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

        VkFormat swapChainImageFormat;
        VkExtent2D swapChainExtent;

        std::vector<Framebuffer> swapChainFramebuffers;
        RenderPass renderPass;

        std::vector<VkImage> depthImages;
        std::vector<VkDeviceMemory> depthImageMemorys;
        std::vector<VkImageView> depthImageViews;
        std::vector<VkImage> swapChainImages;
        std::vector<VkImageView> swapChainImageViews;

        VulkanDevice& m_Device;
        VkExtent2D windowExtent;

        VkSwapchainKHR m_Swapchain;
        VulkanSwapchain* m_OldSwapchain;

        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkFence> inFlightFences;
        std::vector<VkFence> imagesInFlight;
        size_t currentFrame = 0;
    };
    
}