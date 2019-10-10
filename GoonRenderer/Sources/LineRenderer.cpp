#include "LineRenderer.h"
#include "Buffer.h"
namespace gr
{
    void setColor(Buffer* _buffer, int _x, int _y, GRColor _color) noexcept
    {
        unsigned char* data = _buffer->data();
        auto bufferInfo = _buffer->getBufferInfo();
    
        int index = (_x + _y * bufferInfo.width) * bufferInfo.numChannels;
        for (int i = 0; i < bufferInfo.numChannels; i++) 
            data[index + i] = _color[i];
    }
};