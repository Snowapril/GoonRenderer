#pragma once

#include "../details/platform.h"

namespace gm
{
    template <typename Type>
    Type const lerp(Type const& _t1, Type const& _t2, float _p) noexcept;
    
    template <typename Type, int Num>
    vec<Type, Num> const clamp(vec<Type, Num> const& _target, vec<Type, Num> const& _min, vec<Type, Num> const& _max) noexcept;
    
    template <typename Type>
    Type const clamp(Type const& _target, Type const& _min, Type const& _max) noexcept;
    
    template <typename Type>
    Type const saturate(Type const& _target) noexcept;
    
    template <typename Type>
    Type const negate(Type const& _target) noexcept;
    
    template <typename Type, int Num>
    vec<Type, Num> const normalize(vec<Type, Num> const& _v) noexcept;
    
    template <typename Type, int Num>
    vec<Type, Num> const reflect(vec<Type, Num> const& _v, vec<Type, Num> const& _axis) noexcept;
};

#include "transform.inl"