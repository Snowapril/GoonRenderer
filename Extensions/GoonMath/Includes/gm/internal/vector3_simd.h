//! SIMD tutorial
//! http://www.cs.uu.nl/docs/vakken/magr/2017-2018/files/SIMD%20Tutorial.pdf

#pragma once


#include "vector3.h"

#include "nmmintrin.h" // for SSE4.2
#include "immintrin.h" // for AVX 

namespace gm
{
    template <>
    class vector<float, 3> 
    {
    public:
        
    public:
        union
        {
            __m128 simd3;
            float data[3];
            struct 
            {
                float x, y, z;
            };
        };
    }
};