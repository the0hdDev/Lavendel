#include "vtpch.h"
#include "IndexBuffer.h"
#include "Renderer.h"

namespace Velt::Renderer
{


	Ref<IndexBuffer> IndexBuffer::Create(const void* data, u64 size)
	{
		VT_PROFILE_FUNCTION();
		switch (RendererAPI::GetAPI())
		{
		case API::None:    return nullptr;
		case API::Vulkan:  return std::make_shared<VulkanVertexBuffer>(vertexData, vertexCount, vertexStride);
		}
		VT_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}


}