#pragma once


#include "../vector.h"

namespace gm
{
    template <typename T>
    class vector<T, 2> 
    {
    public:
        using value_type = T;
        using size_type  = int;
        
        //! brief : initialize data as uninitialized array.
        vector(  ) = default;
        
        inline vector( vector<T, 2> const& v )
        {
            this->x = v.x;
            this->y = v.x;
        }
        template <typename U>
        inline vector( vector<U, 2> const& v )
        {
            this->x = static_cast<value_type>( v.x );
            this->y = static_cast<value_type>( v.x );
        }
        vector( T e1 )
        {
            this->x = e1;
            this->y = e1;
        }
        vector( T *elements )
        {
            this->x = elements[0];
            this->y = elements[1];
        }
        vector( T x, T y )
        {
            this->x = x;
            this->y = y;
        }
        
        inline value_type& operator[]( int i ) { return data[i]; };
        inline value_type const& operator[]( int i ) const { return data[i]; };
    public:
        union
        {
            value_type data[2];
            struct 
            {
                value_type x, y;
            };
        };
    };
    
    template <typename Type>
    vector<float, 3> barycentric(vector<Type, 2> const& point, vector<Type, 2> const& v0, vector<Type, 2> const& v1, vector<Type, 2> const& v2) noexcept
    {
        Type cy = v2.y - v0.y;
        Type cx = v2.x - v0.x;
        Type by = v1.y - v0.y;
        Type bx = v1.x - v0.x;
        
        float w1 = ( v0.x * cy + (point.y - v0.y) * cx - point.x * cy ) / static_cast<float>(by * cx - bx * cy);
        float w2 = ( point.y - v0.y - w1 * by ) / static_cast<float>(cy);
        
        return vector<float, 3>(w1, w2, 1.0f - w1 - w2);
    }
};