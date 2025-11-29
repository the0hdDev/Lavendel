#pragma once
#include "Lavendel/Core/Core.h"

namespace Lavendel {
namespace RenderAPI {

	struct FramebufferSpecification 
	{
		u32 Width, Height; 
		u32 Samples = 1;

		bool SwapChainTarget = false;
	};

	class Framebuffer
	{
	public:
		virtual const FramebufferSpecification& getSpecification() const = 0;
		static Ref<Framebuffer> Create(const FramebufferSpecification& specs);


		};

	} // namespace RenderAPI
} // namespace Lavendel
