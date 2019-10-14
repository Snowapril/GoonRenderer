#include "Buffer.h"

namespace gr
{
    Buffer::Buffer(int _width, int _height, int _nunChannels, unsigned char *_data) noexcept
        : width(_width), height(_height), numChannels(_nunChannels)
    {
        if (_data) this->buffer = _data;
        else       this->buffer = allocBuffer(width * height * numChannels);
    }
    
    Buffer::~Buffer() noexcept
    {
        deallocBuffer(this->buffer);   
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
        info.bitCount    = 4;
        
        return info;
    }
    
    unsigned char* Buffer::allocBuffer(int _numAlloc) noexcept
    {
        return new unsigned char[_numAlloc];
    }
    
    void Buffer::deallocBuffer(unsigned char *_data) noexcept
    {
        if (_data == nullptr) delete _data;   
    }
};