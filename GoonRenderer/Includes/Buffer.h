#pragma once

#include "DataType.h"

namespace gr
{
    class Buffer 
    {
    protected:
        unsigned char* buffer = nullptr;
        int width       {0};
        int height      {0};
        int numChannels {0};
    public:
        Buffer() = default;
        //! Construct buffer with given parameters.
        //! if _data is nullptr, buffer will be uninitialized.
        Buffer(int _width, int _height, int _nunChannels, unsigned char *_data=nullptr) noexcept;
        ~Buffer() noexcept;
    public:
        //! Return the pointer of first element in the buffer.
        unsigned char* data() noexcept;
        //! Return the const pointer of first element in the buffer
        unsigned char const* data() const noexcept;
        //! Return the information of the buffer which address width, height, number of channels.
        BufferInfo getBufferInfo() const noexcept;
        
        static unsigned char* allocBuffer(int _numAlloc) noexcept;
        static void deallocBuffer(unsigned char *_data) noexcept;
    };
};
