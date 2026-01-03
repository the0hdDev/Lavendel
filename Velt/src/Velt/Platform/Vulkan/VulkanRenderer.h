#include "vtpch.h"
#include "RenderAPI.h"
#include "Velt/Renderer/Renderer.h"

namespace Velt::Renderer::Vulkan
{
	class VELT_API VulkanRenderer : public RenderAPI
	{
	public:
		virtual void DrawIndexed(std::shared_ptr<VertexBuffer>& vertexBuffer, std::sghba);

		virtual void 


	private:
		//void loadModels();
		//void createPipelineLayout();
		//void createPipeline();
		//void createCommandBuffers();
		//void freeCommandBuffers();
		//void recreateSwapChain();
		//void recordCommandBuffer(int imageIndex);


		// std::shared_ptr<Model> m_Model;
		//std::vector<VkCommandBuffer> m_CommandBuffers;
		//VkPipelineLayout m_PipelineLayout;
		//LayerStack* m_LayerStack = nullptr;  // Reference to layer stack for calling OnRender on each layer
	};
}