#include "vec_transform.h"

#include "../property/vec_property.h"

namespace gm
{
    template <typename Type, int Num>
    typename Type dot(vec<Type, Num> const& _v0, vec<Type, Num> const& _v1) noexcept
    {
        Type dot_sum = Type(0);
        for (int i = 0; i < Num; i++)
            dot_sum += _v0.elements[i] * _v1.elements[i];
        return dot_sum;
    }
    
    template <typename Type, int Num>
    vec<Type, Num> const normalize(vec<Type, Num> const& _v) noexcept
    {
        float len = length(_v);
        float len_inv = 1 / len;
        vec<Type, Num> result = _v * len_inv;
        return result;
    }
};
