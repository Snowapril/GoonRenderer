#pragma once

#include "Resource/Resource.h"
#include "DataType.h"

namespace gr
{
    class Buffer : public Resource
    {
    protected:
        unsigned char* buffer = nullptr;
        int width       {0};
        int height      {0};
        int numChannels {0};
    public:
        Buffer() = default;
        /*
        * Construct buffer with given parameters. if _data is nullptr, buffer will be uninitialized.
        * @param buffer width
        * @param buffer height
        * @param number of channels of the buffer
        * @param if _data is nullptr, alloc the buffer with uninitialized data.
        */
        Buffer(int _width, int _height, int _numChannels, unsigned char *_data=nullptr) noexcept;
        ~Buffer() noexcept;
    public:
        //! Return the pointer of first element in the buffer.
        unsigned char* data() noexcept;
        //! Return the const pointer of first element in the buffer
        unsigned char const* data() const noexcept;
        //! Return the information of the buffer which address width, height, number of channels.
        BufferInfo getBufferInfo() const noexcept;
    };
};
