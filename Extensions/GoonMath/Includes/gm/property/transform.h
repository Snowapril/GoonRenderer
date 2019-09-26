#pragma once

#include "../details/type_vec_base.h"

namespace gm
{
    template <int Num, typename Type>
    vec<Num, Type> const clamp(vec<Num, Type> const& _target, vec<Num, Type> const& _min, vec<Num, Type> const& _max) noexcept;
    
    template <typename Type>
    Type const clamp(Type const& _target, Type const& _min, Type const& _max) noexcept;
    
    template <typename Type>
    Type const saturate(Type const& _target) noexcept;
    
    template <typename Type>
    Type const negate(Type const& _target) noexcept;
    
    template <int Num, typename Type>
    vec<Num, Type> const normalize(vec<Num, Type> const& _v) noexcept;
    
    template <int Num, typename Type>
    vec<Num, Type> const reflect(vec<Num, Type> const& _v, vec<Num, Type> const& _axis) noexcept;
};

#include "transform.inl"