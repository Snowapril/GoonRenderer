#pragma once

#include "../details/platform.h"
#include "../details/type_vec3.h"

namespace gm
{
    template <typename Type, int Num>
    float length(vec<Type, Num> const& _v) noexcept;
    
    template <typename Type, int Num>
    Type sum(vec<Type, Num> const& _v) noexcept;
    
    template <typename Type>
    gm::vec<Type, 3> barycentric(gm::vec<Type, 3> const& _point, gm::vec<Type, 3> const& _v0, gm::vec<Type, 3> const& _v1, gm::vec<Type, 3> const& _v2) noexcept;
};

#include "attribute.inl"