#pragma once

namespace gr
{
    struct BufferInfo 
    {
        int width;
        int height;
        int numChannels;
        int bitCount;
    };
    
    enum GoonEnum
    {
        GOON_STATIC_DRAW    = 0x00000000,  
        GOON_DYNAMIC_DRAW   = 0x00000001,
        GOON_SIGNED_CHAR    = 0x00000002,
        GOON_UNSIGNED_CHAR  = 0x00000004,
        GOON_SIGNED_INT     = 0x00000008,
        GOON_UNSIGNED_INT   = 0x00000010,
    };
    
    struct VertexStrideInfo 
    {
        unsigned int size;
        GoonEnum type;
        unsigned int stride;
        unsigned int offset;
    };
    
    using GoonID = unsigned int;
};
