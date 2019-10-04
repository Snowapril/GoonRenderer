#pragma once

#include "../details/type_vec_base.h"

namespace gm
{
    template <int Num, typename Type>
    float length(vec<Num, Type> const& _v) noexcept;
    
    template <int Num, typename Type>
    Type sum(vec<Num, Type> const& _v) noexcept;
};

#include "attribute.inl"