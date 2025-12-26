#pragma once
#include "vtpch.h"
#include "Core/Core.h"
#include "VulkanDevice.h"
#include "Velt/Renderer/Swapchain.h"
#include "Velt/Renderer/Framebuffer.h"
#include <SDL3/SDL.h>

namespace Velt::Renderer::Vulkan {

    struct SwapchainExtent
    {
        u32 Height;
        u32 Width;
    };

    struct SwapchainCreateInfo 
    {
        SwapchainExtent extent;
        bool VSync; 
    };


    class VELT_API VulkanSwapchain
    {
    public:
        static constexpr int MAX_FRAMES_IN_FLIGHT = 3;

        VulkanSwapchain() = default;

        VulkanSwapchain(const VulkanSwapchain&) = delete;
        void operator=(const VulkanSwapchain&) = delete;

        void Init(VkInstance instance);
        void InitSurface(SDL_Window* windowHandle);
        void Create(SwapchainCreateInfo& createInfo);
        void Destroy();

        void OnResize(SwapchainExtent& extend);

        void BeginFrame();
        void Present(); 

        inline VkFramebuffer GetCurrentFramebuffer() { return GetFrameBuffer(m_CurrentFrameIndex); }
        inline VkFramebuffer GetFrameBuffer(int index) { VT_CORE_ASSERT(index < m_Framebuffers.size); return m_Framebuffers[index]; }
		inline u32 GetWidth() const { return m_Width; }
		inline u32 GetHeight() const { return m_Height; }
        inline u32 GetImageCount() const { return (u32)m_SwapChainImages.size(); } 
        inline float GetAspectRatio() const { return (float)m_Width / (float)m_Height; }
        inline VkRenderPass GetRenderPass() { return m_RenderPass; }
		inline VkImageView GetImageView(int index) { return m_SwapChainImageViews[index]; }
        inline SwapchainExtent GetwapchainExtent() { return m_SwapchainExtent; }
        

        VkFormat findDepthFormat();
        
    private:
   /*     void createVulkanSwapchain();
        void createImageViews();
        void createDepthResources();
        void createRenderPass();
        void createFramebuffers();
        void createSyncObjects();*/

		VkResult AcquireNextImage();
        u32 SubmitCommandBuffers(const VkCommandBuffer* buffers, u32* imageIndex);

        VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
        VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
        VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
        VkFormat m_SwapChainImageFormat;

        std::vector<VkFramebuffer> m_Framebuffers;
        VkRenderPass m_RenderPass;

        std::vector<VkImage> m_DepthImages;
        std::vector<VkDeviceMemory> m_DepthImageMemorys;
        std::vector<VkImageView> m_DepthImageViews;
        std::vector<VkImage> m_SwapChainImages;
        std::vector<VkImageView> m_SwapChainImageViews;

        VulkanDevice& m_Device;
        VkExtent2D windowExtent;

        VkSwapchainKHR m_Swapchain;
        VulkanSwapchain* m_OldSwapchain;

        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkFence> inFlightFences;
        std::vector<VkFence> imagesInFlight;

        u32 m_Width;
        u32 m_Height;

        SwapchainExtent m_SwapchainExtent;

        size_t m_CurrentFrame = 0;
        u32 m_CurrentFrameIndex = 0;
    };
    
}

//namespace Velt::Renderer::Vulkan {
//
//	class VELT_API VulkanSwapchain
//	{
//	public:
//		static constexpr int MAX_FRAMES_IN_FLIGHT = 3;
//
//		VulkanSwapchain() = default;
//
//		VulkanSwapchain(const VulkanSwapchain&) = delete;
//		void operator=(const VulkanSwapchain&) = delete;
//
//		virtual Framebuffer* GetFramebuffer(int index) override { return reinterpret_cast<void*>(getFrameBuffer(index)); }
//		virtual void* GetImageView(int index) override { return reinterpret_cast<void*>(getImageView(index)); }
//		// virtual size_t GetImageCount() const override { return swapChainImages.size(); }
//		virtual u32 GetWidth() const override { return swapChainExtent.width; }
//		virtual u32 GetHeight() const override { return swapChainExtent.height; }
//		virtual float GetAspectRatio() const override { return static_cast<float>(swapChainExtent.width) / static_cast<float>(swapChainExtent.height); }
//		virtual int AcquireNextImage(u32& imageIndex) override { return static_cast<int>(acquireNextImage(imageIndex)); }
//		virtual int SubmitCommandBuffers(const void* buffers, u32* imageIndex) override { return static_cast<int>(submitCommandBuffers(reinterpret_cast<const VkCommandBuffer*>(buffers), imageIndex)); }
//
//		Framebuffer getFrameBuffer(int index) { return swapChainFramebuffers[index]; }
//		VkRenderPass getRenderPass() { return renderPass; }
//		VkImageView getImageView(int index) { return swapChainImageViews[index]; }
//		size_t imageCount() { return swapChainImages.size(); }
//		VkFormat getVulkanSwapchainImageFormat() { return swapChainImageFormat; }
//		VkExtent2D getVulkanSwapchainExtent() { return swapChainExtent; }
//		u32 width() { return swapChainExtent.width; }
//		u32 height() { return swapChainExtent.height; }
//
//		float extentAspectRatio()
//		{
//			return static_cast<float>(swapChainExtent.width) / static_cast<float>(swapChainExtent.height);
//		}
//		VkFormat findDepthFormat();
//
//		VkResult acquireNextImage(u32& imageIndex);
//		VkResult submitCommandBuffers(const VkCommandBuffer* buffers, u32* imageIndex);
//
//	private:
//		void init();
//		void createVulkanSwapchain();
//		void createImageViews();
//		void createDepthResources();
//		void createRenderPass();
//		void createFramebuffers();
//		void createSyncObjects();
//
//		VkSurfaceFormatKHR chooseSwapSurfaceFormat(
//			const std::vector<VkSurfaceFormatKHR>& availableFormats);
//		VkPresentModeKHR chooseSwapPresentMode(
//			const std::vector<VkPresentModeKHR>& availablePresentModes);
//		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
//
//		VkFormat m_SwapChainImageFormat;
//		VkExtent2D m_SwapChainExtent;
//
//		std::vector<Framebuffer> swapChainFramebuffers;
//		VkRenderPass m_RenderPass;
//
//		std::vector<VkImage> m_DepthImages;
//		std::vector<VkDeviceMemory> m_DepthImageMemorys;
//		std::vector<VkImageView> m_DepthImageViews;
//		std::vector<VkImage> m_SwapChainImages;
//		std::vector<VkImageView> m_SwapChainImageViews;
//
//		VulkanDevice& m_Device;
//		VkExtent2D windowExtent;
//
//		VkSwapchainKHR m_Swapchain;
//		VulkanSwapchain* m_OldSwapchain;
//
//		std::vector<VkSemaphore> imageAvailableSemaphores;
//		std::vector<VkSemaphore> renderFinishedSemaphores;
//		std::vector<VkFence> inFlightFences;
//		std::vector<VkFence> imagesInFlight;
//		size_t currentFrame = 0;
//	};
//
//}