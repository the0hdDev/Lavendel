#pragma once
#include "vtpch.h"
#include <vulkan/vulkan.h>
#include "Velt/Core/Core.h"
#include "Velt/Platform/Vulkan/VulkanDevice.h"
#include "Velt/Renderer/RenderContext.h"
#include "Velt/Platform/Vulkan/VulkanSwapchain.h"
#include "Velt/Platform/Vulkan/VulkanPipeline.h"
#include "Core/Application.h"

namespace Velt::Renderer::Vulkan
{

	class VELT_API VulkanContext : public RenderContext
	{
	public:
		VulkanContext();
		virtual ~VulkanContext() = default;
		
		virtual void Init() override;
		virtual void Shutdown() override;
		
		static VulkanContext* Get() { return Application::Get().getWindow()->getContext(); }

		static VkInstance getInstance() { return s_VulkanInstance; }
		std::shared_ptr<VulkanDevice> getDevice() { return m_Device; }

	private:

		Ref<VulkanDevice> m_Device;

		// Vulkan instance
		inline static VkInstance s_VulkanInstance;
#if 0
		VkDebugReportCallbackEXT m_DebugReportCallback = VK_NULL_HANDLE;
#endif
		VkDebugUtilsMessengerEXT m_DebugUtilsMessenger = VK_NULL_HANDLE;
		VkPipelineCache m_PipelineCache = nullptr;

		VulkanSwapchain m_SwapChain;

	};
}
