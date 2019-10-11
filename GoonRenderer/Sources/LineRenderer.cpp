#include "LineRenderer.h"
#include "Buffer.h"
#include <cmath>

namespace gr
{
    void setColor(Buffer* _buffer, Pixel _p) noexcept
    {
        unsigned char* data = _buffer->data();
        auto bufferInfo = _buffer->getBufferInfo();
    
        int index = (_p.x + _p.y * bufferInfo.width) * bufferInfo.numChannels;
        for (int i = 0; i < bufferInfo.numChannels; i++) 
            data[index + i] = _p.color[i];
    }
    
    void drawLine(Buffer* _buffer, Pixel _p1, Pixel _p2) noexcept
    {
        // Bresenham's Line Generation Algorithm
        // https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
        // need color lerp between two pixels
        
        float m = (_p2.y - _p1.y) / (_p2.x - _p1.x);
        for (int x = _p1.x; x <= _p2.x; ++x)
        {
            int y = std::round(m * x);
            setColor(_buffer, Pixel(x, y, _p1.color));
        }
    }
};