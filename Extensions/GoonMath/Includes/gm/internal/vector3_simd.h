//! SIMD tutorial
//! http://www.cs.uu.nl/docs/vakken/magr/2017-2018/files/SIMD%20Tutorial.pdf

#pragma once

#include <stdalign.h>

#include "vector3.h"
#include "../util.h"

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
        using value_type = float;
        using size_type  = int;
        
        //! brief : initialize data as uninitialized array.
        vector(  ) = default;
        
        inline vector( vector<float, 3> const& v )
        {
            this->simd3 = v.simd4;
        }
        template <typename U>
        inline vector( vector<U, 3> const& v )
        {
            this->simd3 = simd4f( 
                static_cast<value_type>(v.x),  
                static_cast<value_type>(v.y),
                static_cast<value_type>(v.z),
                            0.0f
            );
        }
        inline vector( simd4f s4 )
        {
            this->simd3 = s4;
        }
        inline vector( float e1 )
        {
            this->simd3 = simd4f( e1 );
        }
        inline vector( float *elements )
        {
            this->simd3 = simd4f( elements );
        }
        inline vector( float x, float  y, float z)
        {
            this->simd3 = simd4f( x, y, z, 0.0f );
        }
        
        inline value_type& operator[]( int i ) { return data[i]; };
        inline value_type const& operator[]( int i ) const { return data[i]; };
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