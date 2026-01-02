#pragma once
#include "vtpch.h"
#include "RenderCommandBuffer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
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

		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexBuffer>& vertexBuffer, const std::shared_ptr<IndexBuffer>& indexBuffer);

		static void RequestShutdown();
		static void Shutdown();

		inline static RenderAPI::API GetAPI() { return RenderAPI::GetAPI(); };

	private:


	};
}
