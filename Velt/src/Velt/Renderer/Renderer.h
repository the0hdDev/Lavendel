#pragma once
#include "vtpch.h"
#include "RenderCommandBuffer.h"
#include "RenderAPI.h"

namespace Velt::Renderer
{
	class Application;
	class LayerStack;



	class VELT_API Renderer
	{
	public:
		Renderer();
		~Renderer();

		// virtual void setImGuiLayer(ImGuiLayer* layer) = 0;
		virtual void setLayerStack(LayerStack* layerStack) = 0;
		
		static void requestShutdown();
		static void Shutdown();

		static void BeginRenderPass(Ref<VkCommandBuffer> renderCommandbuffer, Ref<VkRenderPass> renderPass, bool explicitClear = false);
		static void EndRenderPass(Ref<VkCommandBuffer> renderCommandbuffer);

		inline static RenderAPI::API GetAPI() { return RenderAPI::GetAPI(); };

	private:
		virtual void loadModels() = 0;
		virtual void createPipelineLayout() = 0;
		virtual void createPipeline() = 0;


	};
}
