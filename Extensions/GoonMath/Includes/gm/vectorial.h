#pragma once

#include "gm/vector.h"

namespace gm
{
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