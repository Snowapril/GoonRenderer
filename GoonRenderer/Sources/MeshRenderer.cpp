#include "MeshRenderer.h"
#include "LineRenderer.h"
#include "Buffer.h"

namespace gr
{
    void fillColor(gm::ivec2 _lt, gm::ivec2 _rb, Buffer *_buffer, gm::vec3 _color) noexcept
    {
        unsigned char* data = _buffer->data();
        auto bufferInfo = _buffer->getBufferInfo();
    
        int startIndex = (_lt[0] + _lt[1] * bufferInfo.width) * bufferInfo.numChannels;
        int numCol = _rb[0] - _lt[0];
        int numRow = _rb[1] - _lt[1];
        
        for (int i = 0; i < numRow; i++)
        {
            unsigned char* tempPtr = &data[startIndex + i * bufferInfo.width * bufferInfo.numChannels];
            for (int j = 0; j < numCol; j++)
                for (int k = 0; k < bufferInfo.numChannels; k++)
                    *tempPtr++ = _color[k];
        }
    }  
};