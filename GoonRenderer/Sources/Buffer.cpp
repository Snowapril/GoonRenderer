#include "Buffer.h"
#include "gbmp/bmp_image.h"

namespace gr
{
    Buffer::Buffer(int _width, int _height, int _nunChannels) noexcept
        : width(_width), height(_height), numChannels(_nunChannels)
    {
        allocBuffer();
    }
    
    Buffer::~Buffer() noexcept
    {
        deallocBuffer();   
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
    
    void Buffer::readBMPFile(char const* _path) noexcept
    {
        buffer = gbmp::gbmp_load_image(_path, &width, &height, &numChannels);
    }
    
    void Buffer::writeBMPFile(char const* _path) const noexcept
    {
        gbmp::gbmp_bgr_to_rgb(buffer, width, height, numChannels);
        gbmp::gbmp_write_image(_path, buffer, width, height, numChannels);
    }
    
    void Buffer::allocBuffer() noexcept
    {
        buffer = new unsigned char[width * height * numChannels];
    }
    
    void Buffer::deallocBuffer() noexcept
    {
        if (buffer == nullptr) delete buffer;   
    }
};