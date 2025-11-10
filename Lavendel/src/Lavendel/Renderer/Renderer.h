#pragma once

#include "../Core.h"
#include "Window.h"
#include "Core/Device.h"
#include "Pipeline/Pipeline.h"
#include "Core/Swapchain.h"
#include "../Log.h"

// std
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>

namespace Lavendel
{
	// Forward declaration
	class Application;

	namespace RenderAPI
	{
		class LAVENDEL_API Renderer
		{
		public:
			Renderer(Window& window);
			~Renderer();

			Renderer(const Renderer&) = delete;
			Renderer& operator=(const Renderer&) = delete;
			
			void drawFrame();

		private:
			void createPipelineLayout();
			void createPipeline();
			void createCommandBuffers();

			Window& m_Window;
			std::shared_ptr<GPUDevice> m_Device;
			std::shared_ptr<SwapChain> m_SwapChain;
			std::shared_ptr<RenderAPI::Pipeline> m_Pipeline;
			std::vector<VkCommandBuffer> m_CommandBuffers;
			std::shared_ptr<PipelineLayout>
		};
	}
}
