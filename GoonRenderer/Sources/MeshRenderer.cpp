#include "MeshRenderer.h"
#include "LineRenderer.h"
#include "Buffer.h"
#include "Util.h"
#include <cstring>
#include <limits>

#include <gm/vectorial.h>

namespace gr
{
    void rectangle(gm::ivec2 _bbmin, gm::ivec2 _bbmax, Buffer *_buffer, gm::vec3 _color) noexcept
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
                std::memcpy(tempPtr + j * 3, _color.data, 3);
        }
    }
    
    //! triangle rasterization algorithm.
    /*
    * youtu.be/HYAgJN3x4GA?list=PLFt_AvWsXl0cD2LPxcjxVjWTQLxJqKpgZ
    */
    void triangle(gm::ivec2 *_vertices, Buffer *_buffer, gm::vec3 *_colors) noexcept
    {
        //! find bounding box min and max
        gm::ivec2 bbMin(std::numeric_limits<int>::max()), bbMax(std::numeric_limits<int>::min());
        for (int i = 0; i < 3; ++i)
        {
            bbMin = gm::ivec2( min(bbMin.x, _vertices[i].x), min(bbMin.y, _vertices[i].y));
            bbMax = gm::ivec2( max(bbMax.x, _vertices[i].x), max(bbMax.y, _vertices[i].y));
        }
        
        //! get barycentric coordinates of all pixels in the bounding box.
        for (int x = bbMin.x; x <= bbMax.x; ++x)
        {
            for (int y = bbMin.y; y <= bbMax.y; ++y)
            {
                gm::vec3 coord = barycentric(gm::ivec2(x, y), _vertices[0], _vertices[1], _vertices[2]);
                //! Check whether vertex (x, y) is on the triangle or not
                if (coord.x >= 0.0f && coord.y >= 0.0f && coord.z >= 0.0f)
                {
                    //! interpolates colors with barycentric coordinates.
                    gm::vec3 interpolated_color = _colors[0] * coord.x + _colors[1] * coord.y + _colors[2] * coord.z;
                    setColor(gm::ivec2(x, y), _buffer, interpolated_color);
                }
            }
        }
        
    }
};