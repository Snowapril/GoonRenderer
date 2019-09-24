#pragma once

#include "../details/type_vec_base.h"

namespace gm
{
    template <typename Type, int Num>
    float length(vec<Type, Num> const& _v) noexcept;
    
    template <typename Type, int Num>
    typename Type sum(vec<Type, Num> const& _v) noexcept;
    
    
};

#include "attribute.inl"