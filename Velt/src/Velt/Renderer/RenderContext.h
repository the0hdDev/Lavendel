#pragma once
#include "Velt/Core/Core.h"

namespace Velt::Renderer
{
	class RenderContext
	{
	public:
		RenderContext() = default;
		virtual ~RenderContext() = default;

		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		static std::shared_ptr<RenderContext> Create();
	};
}

