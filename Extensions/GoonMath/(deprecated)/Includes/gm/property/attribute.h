#pragma once

#include "../details/platform.h"
#include "../details/type_vec3.h"

namespace gm
{
    template <size_t Num, typename Type>
    float length(vec<Num, Type> const& _v) noexcept;
    
    template <size_t Num, typename Type>
    Type sum(vec<Num, Type> const& _v) noexcept;
    
    template <typename Type>
    gm::vec<3, Type> barycentric(gm::vec<3, Type> const& _point, gm::vec<3, Type> const& _v0, gm::vec<3, Type> const& _v1, gm::vec<3, Type> const& _v2) noexcept;
};

#include "attribute.inl"