#include "LineRenderer.h"
#include "Buffer.h"
#include <cmath>


namespace gr
{
    void setColor(gm::vec3 _v, Buffer* _buffer, gm::vec3 _color) noexcept
    {
        unsigned char* data = _buffer->data();
        auto bufferInfo = _buffer->getBufferInfo();
    
        int index = (_v.x + _v.y * bufferInfo.width) * bufferInfo.numChannels;
        for (int i = 0; i < bufferInfo.numChannels; i++) 
            data[index + i] = _color[i];
    }
    
    void drawLine(gm::vec3 _v1, gm::vec3 _v2, Buffer* _buffer, gm::vec3 _color) noexcept
    {
        // Bresenham's Line Generation Algorithm
        // https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
        // need color lerp between two pixels
        
        
    }
};