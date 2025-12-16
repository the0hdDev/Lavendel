#include "vtpch.h"
#include "VertexBuffer.h"
#include "RendererAPI.h"
#include "Platform/Vulkan/VulkanVertexBuffer.h"

namespace Velt::Renderer
{
    
	std::shared_ptr<VertexBuffer> VertexBuffer::Create(const void* vertexData, u64 vertexCount, u64 vertexStride)
	{
		switch (RendererAPI::GetAPI())
		{
			case API::None:    return nullptr;
			case API::Vulkan:  return std::make_shared<VulkanVertexBuffer>(vertexData, vertexCount, vertexStride);
		}
		VT_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}