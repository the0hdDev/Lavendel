#pragma once
#include "Velt/Core/Core.h"

namespace Velt::Renderer
{
    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() {};

        virtual void Bind() const = 0;
        
        virtual void CreateBuffer(void* buffer, u64 size, u64 offset = 0);

        virtual u32 GetCount() const;
        virtual u64 GetSize() const;
        virtual u32 GetRendererID() const;

        static Ref<IndexBuffer> Create(u64 size);
        static Ref<IndexBuffer> Create(void* data, u64 size = 0);
    };
} 