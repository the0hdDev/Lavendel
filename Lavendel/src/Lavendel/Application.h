#pragma once
#include "Core.h"
#include "Renderer/Window.h"
#include "Renderer/Core/Device.h"
#include "Renderer/Pipeline/Pipeline.h"
#include <string>


namespace Lavendel
{

	class LAVENDEL_API Application
	{
		public:
			Application();
			virtual ~Application();
			void Run();

			static constexpr int WIDTH = 1280;
			static constexpr int HEIGHT = 1280;
			std::string TITLE{ "Lavendel Engine" };

	private:

		Lavendel::RenderAPI::Window m_Window{1280, 720, "Lavendel Window", false };
		Lavendel::RenderAPI::GPUDevice m_Device{m_Window };
		Lavendel::RenderAPI::Pipeline m_Pipeline{m_Device, "shaders/shader.vert.spv", "shaders/shader.frag.spv", Lavendel::RenderAPI::Pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
		};
	};

	// MUST BE DEFINED IN CLIENT

	Application* CreateApplication();

}
