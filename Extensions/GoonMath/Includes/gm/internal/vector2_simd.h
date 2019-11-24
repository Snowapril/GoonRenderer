//! SIMD tutorial
//! http://www.cs.uu.nl/docs/vakken/magr/2017-2018/files/SIMD%20Tutorial.pdf

#pragma once

#include <stdalign.h>
#include "../util.h"
#include "vector2.h"

#ifdef GM_SIMD_SUPPORT
#include "../simd/simd2f.h"
#endif

namespace gm
{
    #ifdef GM_SIMD_SUPPORT
    template <>
    class vector<float, 2> 
    {
    public:
        
    public:
        union
        {
            simd2f simd2;
            alignas( 8 ) float data[2];
            struct 
            {
                alignas( 8 ) float x, y;
            };
        };
    };
    #endif
};