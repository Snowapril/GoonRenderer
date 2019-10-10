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
        Buffer(int _width, int _height, int _nunChannels) noexcept;
        virtual ~Buffer() noexcept;
    public:
        unsigned char* data() noexcept;
        unsigned char const* data() const noexcept;
        BufferInfo getBufferInfo() const noexcept;
        void readBMPFile(char const* _path) noexcept;
        void writeBMPFile(char const* _path) const noexcept;
        void allocBuffer() noexcept;
        void deallocBuffer() noexcept;
    };
};
