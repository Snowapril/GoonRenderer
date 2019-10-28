#pragma once

namespace gr
{
    //! POD for representing specificity of buffer.
    struct BufferInfo 
    {
        int width;
        int height;
        int numChannels;
        //! If Buffer's data type have n byes, bitCount will be n * 8.
        int bitCount;
    };
    
    enum GoonEnum
    {
        //! If Vertices data will never be changed after uploading to current context, 
        //! this flag will improve some performance.
        GOON_STATIC_DRAW    = 0x00000000,  
        
        //! If Vertices data will be changed frequently, This flag must be checked.
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
