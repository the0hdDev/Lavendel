#pragma once
#include "Velt/Core/Core.h"
#include "Velt/Renderer/VertexBuffer.h"
#include <vulkan/vulkan.h>

namespace Velt::Renderer
 {
    struct VulkanVertexBufferElement
    {
		u64 size;
		void* data;
	};

    class VulkanVertexBuffer : public VertexBuffer
    {
    public:

        VulkanVertexBuffer(VertexBufferElement& elements);

        virtual ~VulkanVertexBuffer() {}

        virtual void Bind() const;
        virtual void Unbind() const;

    private:
        u32 m_RendererID{};
    };
 }