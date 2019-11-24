//! SIMD tutorial
//! http://www.cs.uu.nl/docs/vakken/magr/2017-2018/files/SIMD%20Tutorial.pdf

#pragma once

#include <stdalign.h>
#include "../util.h"
#include "vector3.h"

#ifdef GM_SIMD_SUPPORT
#include "../simd/simd4f.h"
#endif

namespace gm
{
    #ifdef GM_SIMD_SUPPORT
    template <>
    class vector<float, 3> 
    {
    public:
        
    public:
        union
        {
            simd4f simd3;
            alignas( 16 ) float data[3];
            struct 
            {
                alignas( 16 ) float x, y, z;
            };
        };
    };
    #endif
};