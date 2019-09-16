#pragma once

#include "../details/type_vec_base.h"

namespace gm
{
    template <typename Type, int Num>
    typename Type dot(vec<Type, Num> const& _v0, vec<Type, Num> const& _v1) noexcept;
    
    template <typename Type, int Num>
    vec<Type, Num> const normalize(vec<Type, Num> const& _v) noexcept;
};

#include "vec_transform.inl"