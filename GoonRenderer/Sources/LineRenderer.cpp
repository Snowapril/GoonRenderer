#include "LineRenderer.h"
#include "Buffer.h"
#include <cmath>
#include <utility>

namespace gr
{
    void setColor(gm::ivec2 _v, Buffer* _buffer, gm::vec3 _color) noexcept
    {
        unsigned char* data = _buffer->data();
        auto bufferInfo = _buffer->getBufferInfo();
        
        const int maxValue = (1 << bufferInfo.bitCount) - 1;
        const int index = (_v.x + _v.y * bufferInfo.width) * bufferInfo.numChannels;
        
        for (int i = 0; i < bufferInfo.numChannels; i++) 
            data[index + i] = static_cast<unsigned char>(maxValue * _color[i]);
    }
    
    void drawLine(gm::ivec2 _v1, gm::ivec2 _v2, Buffer* _buffer, gm::vec3 _color) noexcept
    {
        // Bresenham's Line Generation Algorithm
        // https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
        
        int dx = std::abs(_v2.x - _v1.x);
        int sx = _v1.x < _v2.x ? 1 : -1;
        int dy = -std::abs(_v2.y - _v1.y);
        int sy = _v1.y < _v2.y ? 1 : -1;
        
        int err = dx + dy;
        
        while (true)
        {
            if (_v1.x == _v2.x && _v1.y ==_v2.y) break;
            setColor(_v1, _buffer, _color);
            float err2 = 2 * err;
            if (err2 >= dy) 
            {
                err += dy;
                _v1.x += sx;
            }
            if (err2 <= dx) 
            {
                err += dx;
                _v1.y += sy;
            }
        }
    }
};