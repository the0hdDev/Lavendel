#pragma once
#include "Velt/Core/Core.h"
#include "Velt/Renderer/RenderCommandBuffer.h"

namespace Velt::Renderer
{
	class RenderPass
	{
	public:
		RenderPass() = default;
		virtual ~RenderPass() = default;

		virtual void Init() = 0;
		virtual void Begin(Ref<RenderCommandBuffer> commandBuffer, void* framebuffer, bool explicitClear = false) = 0;
		virtual void End(Ref<RenderCommandBuffer> commandBuffer) = 0;
		virtual void* GetNativeHandle() = 0;

		static Ref<RenderPass> Create();
	};
}

