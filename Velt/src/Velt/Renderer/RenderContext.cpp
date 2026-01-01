#include "RenderContext.h"
#include "Renderer.h"
#include "Platform/Vulkan/VulkanContext.h"
#include "RenderAPI.h"

namespace Velt::Renderer
{

	Context* Context::Create()
	{		
		VT_PROFILE_FUNCTION();
		switch (Renderer::GetAPI())
		{
		case RenderAPI::API::None:    return nullptr;
		case RenderAPI::API::Vulkan:  return new Vulkan::VulkanContext;
		}
		VT_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
		
	}

}