#include "Context.h"
#include "Object/VBO.h"
#include "Buffer.h"

#include <cassert>

namespace gr
{
    Context::~Context() noexcept
    {
        for (int i = 0; i < staticVBOs.size(); ++i)
            if ( staticVBOs[i]) delete staticVBOs[i];
        for (int i = 0; i < dynamicVBOs.size(); ++i)
            if (dynamicVBOs[i]) delete dynamicVBOs[i];
            
        staticVBOs.clear();
        dynamicVBOs.clear();
    }
    
    GoonID Context::generateVBO(void *_data, std::vector< VertexStrideInfo >&& _vStrideInfos, GoonEnum _usage) noexcept
    {
        GoonID objectID = -1;
        
        switch(_usage)
        {
        case GOON_STATIC_DRAW :
            staticVBOs.push_back(new VBO(_data, std::move(_vStrideInfos)));
            objectID = static_cast<GoonID>(staticVBOs.size() - 1);
            break;
        case GOON_DYNAMIC_DRAW :
            dynamicVBOs.push_back(new VBO(_data, std::move(_vStrideInfos)));
            objectID = static_cast<GoonID>(dynamicVBOs.size() - 1);
            break;
        default:
            assert(false);
            break;
        }
        return objectID;
    }
    
    GoonID Context::generateBuffer(int _width, int _height, int _numChannels, unsigned char *_data)
    {
        buffers.push_back(new Buffer(_width, _height, _numChannels, _data));
        return static_cast<GoonID>(buffers.size());
    }
    
    Buffer* Context::getBufferByIndex(int _id) noexcept
    {
        return buffers[_id];
    }
};