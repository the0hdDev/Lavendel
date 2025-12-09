#include "vtpch.h"
#include "RenderPass.h"

#include "Renderer.h"

#include "Velt/Platform/Vulkan/VulkanRenderPass.h"

#include "Velt/Renderer/RendererAPI.h"

namespace Velt::Renderer {

	Ref<RenderPass> RenderPass::Create(const RenderPassSpecification& spec)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    assert(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPIType::Vulkan:  return Ref<VulkanRenderPass>::Create(spec);
		}

		assert(false, "Unknown RendererAPI!");
		return nullptr;
	}

}