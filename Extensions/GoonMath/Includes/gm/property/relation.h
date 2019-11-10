#pragma once

#include "../details/type_vec_base.h"
#include "../details/type_vec3.h"

namespace gm
{
    template <int Num, typename Type>
    typename Type dot(vec<Num, Type> const& _v0, vec<Num, Type> const& _v1) noexcept;
    
    template <typename Type>
    gm::vec<3, Type> cross(gm::vec<3, Type> const& _v0, gm::vec<3, Type> const& _v1) noexcept;
    
    template <typename Type>
    Type const clamp(Type const& _target, Type const& _min, Type const& _max) noexcept;
};

#include "relation.inl"