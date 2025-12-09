#pragma once
#include "Velt/Core/Core.h"

namespace Velt::Renderer
{

    struct VertexBufferElement
    {
        u32 Size;
        float *Data;
    };

    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() {};

//        virtual void SetData(const void* data, u32 size) = 0;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        

        static VertexBuffer* Create(VertexBufferElement* elements);
    }
} 