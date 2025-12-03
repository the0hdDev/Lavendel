#include "Framebuffer.h"
#include "Lavendel/Plattform/Vulkan/VulkanFramebuffer.h"
#include "Lavendel/Renderer/Renderer.h"
#include "lvpch.h"

namespace Lavendel::Renderer {

  Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification &spec) {
    return CreateRef<VulkanFramebuffer>(Renderer::getDevice(), spec);
}


} // namespace Lavendel
