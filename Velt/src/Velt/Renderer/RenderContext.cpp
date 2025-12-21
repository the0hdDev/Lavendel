#include "RenderContext.h"
#include "Renderer.h"
#include "Platform/Vulkan/VulkanContext.h"

namespace Velt::Renderer 
{
	std::shared_ptr<RenderContext> RenderContext::Create()
	{
			VT_PROFILE_FUNCTION();
			switch (Renderer::GetAPI())
			{
			case RendererAPI::None:    return nullptr;
			case RendererAPI::Vulkan:  return std::make_shared<Vulkan::VulkanContext>();
			}
			VT_CORE_ASSERT(false, "Unknown RendererAPI");
			return nullptr;
	}
}