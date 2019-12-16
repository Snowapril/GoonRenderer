#pragma once

//! LLDB commands cheat sheet : https://lldb.llvm.org/use/map.html

#include "gm/vector.h"
#include "gm/bitwise.h"

namespace gm
{
    //! return whether if given three vertices compose triangle or not.
    template <typename Type, int Dims>
    bool checkTriangle(vector<Type, Dims> const& v0, vector<Type, Dims> const& v1, vector<Type, Dims> const& v2) noexcept
    {
        Type dy0 = v0.y - v1.y;
        Type dy1 = v1.y - v2.y;
        Type zero(0);

        if (Bitwise::anyOf(dy0 == zero, dy1 == zero)) return false;

        Type m0 = (v0.x - v1.x) / dy0;
        Type m1 = (v1.x - v2.x) / dy1;

        if (m0 == m1) return false;

        return true;
    }

    template <typename Type>
    vector<float, 3> barycentric(vector<Type, 2> const& point, vector<Type, 2> const& v0, vector<Type, 2> const& v1, vector<Type, 2> const& v2) noexcept
    {
        if ( checkTriangle(v0, v1, v2)  == false )
            return vector<float, 3>(-1.0f, -1.0f, -1.0f);

        Type cy = v2.y - v0.y;
        Type cx = v2.x - v0.x;
        Type by = v1.y - v0.y;
        Type bx = v1.x - v0.x;
        
        float w1 = ( v0.x * cy + (point.y - v0.y) * cx - point.x * cy ) / static_cast<float>(by * cx - bx * cy);
        float w2 = ( point.y - v0.y - w1 * by ) / static_cast<float>(cy);
        
        return vector<float, 3>(w1, w2, 1.0f - w1 - w2);
    }  
};