#include "vtpch.h"
#include "Renderer/RenderAPI.h"
#include "Velt/Renderer/Renderer.h"

namespace Velt::Renderer::Vulkan
{
	class VELT_API VulkanRenderer : public RenderAPI
	{
	public:
		

		void Clear() override;
		void SetClearColor(const glm::vec4& color) override;

		void DrawIndexed(const std::shared_ptr<VertexBuffer>& vertexBuffer, std::shared_ptr<IndexBuffer>& indexBuffer) override;

	private:

	};
}