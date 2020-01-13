#include "Buffer.h"

namespace gr
{
    Buffer::Buffer(int width, int height, int numChannels, unsigned char *data) noexcept
        : width(width), height(height), numChannels(numChannels)
    {
        if (data) this->buffer = data;
        else      this->buffer = new unsigned char[width * height * numChannels];
    }
    
    Buffer::~Buffer() noexcept
    {
        if (this->buffer == nullptr) delete this->buffer;   
    }
    
    unsigned char* Buffer::data() noexcept
    {
        return static_cast<unsigned char*>(buffer);
    }
    
    unsigned char const* Buffer::data() const noexcept
    {
        return static_cast<unsigned char const*>(buffer);
    }
    
    BufferInfo Buffer::getBufferInfo() const noexcept
    {
        BufferInfo info;
        info.width       = this->width;
        info.height      = this->height;
        info.numChannels = this->numChannels;
        info.bitCount    = sizeof(unsigned char) * 8;
        
        return info;
    }
};