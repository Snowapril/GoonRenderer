#pragma once

#include "DataType.h"

namespace gr
{
    // Color buffer class can be a member of framebuffer or texture, etc..
    class Buffer 
    {
    protected:
        unsigned char* buffer = nullptr;
        int width       {0};
        int height      {0};
        int numChannels {0};
    public:
        Buffer() = default;
        Buffer(int _width, int _height, int _nunChannels, unsigned char *_data=nullptr) noexcept;
        virtual ~Buffer() noexcept;
    public:
        unsigned char* data() noexcept;
        unsigned char const* data() const noexcept;
        BufferInfo getBufferInfo() const noexcept;
        
        static unsigned char* allocBuffer(int _numAlloc) noexcept;
        static void deallocBuffer(unsigned char *_data) noexcept;
    };
};
