#include "lvpch.h"
#include "Framebuffer.h"

#include "Plattform/VulkanFramebuffer.h"

namespace Lavendel {
	namespace RenderAPI {

		Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
		{
			return CreateRef<VulkanFramebuffer>(spec);
		}
		

	}
}
