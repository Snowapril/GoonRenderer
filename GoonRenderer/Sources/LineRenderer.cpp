#include "LineRenderer.h"
#include "Buffer.h"
#include <cmath>
#include <utility>

namespace gr
{
    void setColor(gm::vec2 _v, Buffer* _buffer, gm::vec3 _color) noexcept
    {
        unsigned char* data = _buffer->data();
        auto bufferInfo = _buffer->getBufferInfo();
    
        int index = (_v.x + _v.y * bufferInfo.width) * bufferInfo.numChannels;
        for (int i = 0; i < bufferInfo.numChannels; i++) 
            data[index + i] = _color[i];
    }
    
    void drawLine(gm::vec2 _v1, gm::vec2 _v2, Buffer* _buffer, gm::vec3 _color) noexcept
    {
        // Bresenham's Line Generation Algorithm
        // https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
        // need color lerp between two pixels
        const float epsilon = 0.001f;
        float err = 0.0f;
        if (_v1.x > _v2.x) std::swap(_v1, _v2);
        const float slope = static_cast<float>(_v2.y - _v1.y) / static_cast<float>(_v2.x - _v1.x);
        bool bPositiveSlope = slope > 0.0f;
        
        for (int x1 = _v1.x, x2 = _v2.x, y = _v1.y; x1 <= x2; ++x1)
        {
            setColor(gm::vec2(x1, y), _buffer, _color);
            err += slope;
            
            if (bPositiveSlope)
            {
                while (err >= 1.0f)
                {
                    ++y;
                    err -= 1.0f;
                    if (err > epsilon)
                        setColor(gm::vec2(x1, y), _buffer, _color);
                }
            }
            else
            {
                // TODO
            }
        }
    }
};