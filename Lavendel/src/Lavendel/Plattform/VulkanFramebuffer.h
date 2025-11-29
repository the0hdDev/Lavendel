#pragma once
#include "Lavendel/Renderer/Framebuffer.h"

namespace Lavendel {
    namespace RenderAPI {

		class VulkanFramebuffer : public Framebuffer
        {
        public:
            VulkanFramebuffer(const FramebufferSpecification& specs) {};

			const FramebufferSpecification& getSpecification() const override { return m_Specification; }
        private:
			FramebufferSpecification m_Specification;
        };

    }

 }
