#pragma once 

#include "VertexBuffer.h"
#include "Velt/Core/Core.h"
#include "IndexBuffer.h"
#include <glm/glm.hpp>

namespace Velt::Renderer {

    class RenderAPI
    {
    public:

        enum class API
        {
            None = 0,
            Vulkan = 1,
            D3D12 = 2,
            METAL = 3
        };

        virtual void Clear() = 0;
        virtual void SetClearColor(const glm::vec4& color) = 0;

        virtual void DrawIndexed(const std::shared_ptr<VertexBuffer>& vertexBuffer, std::shared_ptr<IndexBuffer>& indexBuffer) = 0;
        
        inline static API GetAPI() { return s_API; }

    private:
        
        static API s_API;
    };

}