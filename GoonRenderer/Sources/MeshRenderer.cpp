#include "MeshRenderer.h"
#include "LineRenderer.h"
#include "Buffer.h"
#include <cstdio>

namespace gr
{
    inline void fillColor(gm::ivec2 _bbmin, gm::ivec2 _bbmax, Buffer *_buffer, gm::vec3 _color) noexcept
    {
        unsigned char* data = _buffer->data();
        auto bufferInfo = _buffer->getBufferInfo();
        
        const int maxValue = (1 << bufferInfo.bitCount) - 1;
        const int startIndex = (_bbmin[0] + _bbmin[1] * bufferInfo.width) * bufferInfo.numChannels;
        const int numCol = _bbmax[0] - _bbmin[0];
        const int numRow = _bbmax[1] - _bbmin[1];
        
        for (int i = 0; i < numRow; i++)
        {
            unsigned char* tempPtr = &data[startIndex + i * bufferInfo.width * bufferInfo.numChannels];
            for (int j = 0; j < numCol; j++)
                memcpy(tempPtr + j * 3, _color.elements, 3);
        }
    }
    
    inline void triangle(gm::ivec2 _v0, gm::ivec2 _v1, gm::ivec2 _v2, Buffer *_buffer, gm::vec3 _color) noexcept
    {
        
    }
};