#pragma once
#include "vtpch.h"
#include <vulkan/vulkan.h>
#include "Velt/Core/Core.h"
#include "Velt/Platform/Vulkan/VulkanDevice.h"
#include "Velt/Renderer/RenderContext.h"
#include "Velt/Platform/Vulkan/VulkanSwapchain.h"
#include "Velt/Platform/Vulkan/VulkanPipeline.h"


namespace Velt::Renderer::Vulkan
{

	class VELT_API VulkanContext : public RendererContext
	{
	public:
		VulkanContext();
		virtual ~VulkanContext() = default;
		virtual void Init() override;
		virtual void Shutdown() override;

		static VulkanDevice* GetDevice() { return s_Device; }
		static VkInstance GetInstance() { return s_Instance; }

	private:

		inline static VkInstance s_Instance; 

		static VulkanDevice* s_Device;
		
		VulkanSwapchain* s_Swapchain;
		
	};
}
