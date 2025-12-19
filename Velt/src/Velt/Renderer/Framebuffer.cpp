#include "Framebuffer.h"
#include "Velt/Platform/Vulkan/VulkanFramebuffer.h"
#include "Velt/Renderer/Renderer.h"
#include "vtpch.h"

namespace Velt::Renderer {

    Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec) 
    {
        VT_PROFILE_FUNCTION();
        return CreateRef<Vulkan::VulkanFramebuffer>(Vulkan::VulkanContext::getDevice(), spec);

    };
} // namespace Velt
