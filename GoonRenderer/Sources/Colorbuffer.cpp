#include "Colorbuffer.h"
#include "gbmp/bmp_image.h"

namespace gr
{
    Colorbuffer::Colorbuffer(int _width, int _height, int _nunChannels) noexcept
        : width(_width), height(_height), numChannels(_nunChannels)
    {
        allocBuffer();
        fillColor(0, _height, _width, 0, GRColor::Black);
    }
    
    Colorbuffer::~Colorbuffer() noexcept
    {
        deallocBuffer();   
    }
    
    unsigned char* Colorbuffer::data() noexcept
    {
        return static_cast<unsigned char*>(buffer);
    }
    
    unsigned char const* Colorbuffer::data() const noexcept
    {
        return static_cast<unsigned char const*>(buffer);
    }
    
    void Colorbuffer::setColor(int _x, int _y, GRColor _color) noexcept
    {
        int index = getBufferIndex(_x, _y);
        for (int i = 0; i < numChannels; i++) 
            buffer[index + i] = _color[i];
    }
    
    void Colorbuffer::fillColor(int _l, int _b, int _r, int _t, GRColor _color) noexcept
    {
        int startIndex = getBufferIndex(_l, _t);
        int numCol = _r - _l;
        int numRow = _b - _t;
        
        for (int i = 0; i < numRow; i++)
        {
            unsigned char* tempPtr = &buffer[startIndex + i * width * numChannels];
            for (int j = 0; j < numCol; j++)
                for (int k = 0; k < numChannels; k++)
                    *tempPtr++ = _color[k];
        }
    }
    
    void Colorbuffer::readBMPFile(char const* _path) noexcept
    {
        buffer = gbmp::gbmp_load_image(_path, &width, &height, &numChannels);
    }
    
    void Colorbuffer::writeBMPFile(char const* _path) const noexcept
    {
        gbmp::gbmp_bgr_to_rgb(buffer, width, height, numChannels);
        gbmp::gbmp_write_image(_path, buffer, width, height, numChannels);
    }
    
    void Colorbuffer::allocBuffer() noexcept
    {
        buffer = new unsigned char[width * height * numChannels];
    }
    
    void Colorbuffer::deallocBuffer() noexcept
    {
        if (buffer == nullptr) delete buffer;   
    }
};