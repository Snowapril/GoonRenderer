#include "MeshRenderer.h"
#include "LineRenderer.h"
#include "Buffer.h"

namespace gr
{
    void fillColor(Buffer *_buffer, int _l, int _b, int _r, int _t, GRColor _color) noexcept
    {
        unsigned char* data = _buffer->data();
        auto bufferInfo = _buffer->getBufferInfo();
    
        int startIndex = (_l + _t * bufferInfo.width) * bufferInfo.numChannels;
        int numCol = _r - _l;
        int numRow = _b - _t;
        
        for (int i = 0; i < numRow; i++)
        {
            unsigned char* tempPtr = &data[startIndex + i * bufferInfo.width * bufferInfo.numChannels];
            for (int j = 0; j < numCol; j++)
                for (int k = 0; k < bufferInfo.numChannels; k++)
                    *tempPtr++ = _color[k];
        }
    }  
};