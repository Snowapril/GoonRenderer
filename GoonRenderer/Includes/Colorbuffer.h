#pragma once

#include "DataType.h"

namespace gr
{
    // Color buffer class can be a member of framebuffer or texture, etc..
    class Colorbuffer 
    {
    protected:
        unsigned char* buffer = nullptr;
        int width       {0};
        int height      {0};
        int numChannels {0};
    public:
        Colorbuffer() = default;
        Colorbuffer(int _width, int _height, int _nunChannels) noexcept;
        ~Colorbuffer() noexcept;
    public:
        unsigned char* data() noexcept;
        unsigned char const* data() const noexcept;
        void setColor(int _x, int _y, GRColor _color) noexcept;
        void fillColor(int _l, int _b, int _r, int _t, GRColor _color) noexcept;
        void readBMPFile(char const* _path) noexcept;
        void writeBMPFile(char const* _path) const noexcept;
        void allocBuffer() noexcept;
        void deallocBuffer() noexcept;
    private:
        inline int getBufferIndex(int _x, int _y) const noexcept
        {
            return (_x + _y * width) * numChannels;
        }
    };
};
