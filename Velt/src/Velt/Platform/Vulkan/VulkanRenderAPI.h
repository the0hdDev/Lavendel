#pragma once
#include "Renderer/RenderAPI.h"
#include "Core/Core.h"


namespace Velt::Renderer::Vulkan {

	class VELT_API VulkanRenderAPI : RenderAPI 
	{
	
	public:
		void Clear() override;
		void SetClearColor(const glm::vec4& color) override;

		void DrawIndexed(const std::shared_ptr<VertexBuffer>& vertexBuffer, std::shared_ptr<IndexBuffer>& indexBuffer) override;

	};

}