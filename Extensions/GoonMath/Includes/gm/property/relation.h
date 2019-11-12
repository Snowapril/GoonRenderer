#pragma once

#include "../details/platform.h"
#include "../details/type_vec3.h"

namespace gm
{
    template <typename Type, int Num>
    typename Type dot(vec<Type, Num> const& _v0, vec<Type, Num> const& _v1) noexcept;
    
    template <typename Type>
    gm::vec<Type, 3> cross(gm::vec<Type, 3> const& _v0, gm::vec<Type, 3> const& _v1) noexcept;
    
    template <typename Type>
    Type const clamp(Type const& _target, Type const& _min, Type const& _max) noexcept;
};

#include "relation.inl"