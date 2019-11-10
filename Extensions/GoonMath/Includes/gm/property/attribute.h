#pragma once

#include "../details/type_vec_base.h"
#include "../details/type_vec3.h"

namespace gm
{
    template <int Num, typename Type>
    float length(vec<Num, Type> const& _v) noexcept;
    
    template <int Num, typename Type>
    Type sum(vec<Num, Type> const& _v) noexcept;
    
    template <typename Type>
    gm::vec<3, Type> barycentric(gm::vec<3, Type> const& _point, gm::vec<3, Type> const& _v0, gm::vec<3, Type> const& _v1, gm::vec<3, Type> const& _v2) noexcept;
};

#include "attribute.inl"