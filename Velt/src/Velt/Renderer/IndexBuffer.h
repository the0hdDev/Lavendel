#pragma once
#include "Velt/Core/Core.h"

namespace Velt::Renderer
{

    struct IndexBufferElement
    {
        u32 Size;
        u32 *indices;
    };

    class IndexBuffer
    {
    public:
        virtual ~VertexBuffer() {};

//        virtual void SetData(const void* data, u32 size) = 0;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        

        static IndexBuffer* Create(IndexBufferElement* elements);
    }
} 