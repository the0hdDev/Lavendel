#include "vtpch.h"
#include "VulkanVertexBuffer.h"

namespace Velt::Renderer
{
	VulkanVertexBuffer::VulkanVertexBuffer(VertexBufferElement& elements)
	{
		VT_CORE_TRACE("Creating Vulkan Vertex Buffer");
		auto device = VulkanContext::GetCurrentDevice()->device();
	
	}
	VulkanVertexBuffer::~VulkanVertexBuffer()
	{
		VT_CORE_TRACE("Destroying Vulkan Vertex Buffer");

	}
	void VulkanVertexBuffer::Bind() const
	{

	}
	void VulkanVertexBuffer::Unbind() const
	{

	}
}