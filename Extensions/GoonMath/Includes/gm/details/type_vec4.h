#pragma once

#include "type_vec_base.h"

namespace gm 
{
    template <typename Type>
    class vec <Type, 4>
    {
    public:
        union 
        {
            Type elements[4];
            struct 
            { 
                Type x { Type(0) };
                Type y { Type(0) };
                Type z { Type(0) };
                Type w { Type(0) };
            };
        };
    public:
        vec() = default;
        vec(Type _val) noexcept;
        vec(Type _x, Type _y, Type _z) noexcept;
        vec<Type, 4> const operator+(vec<Type, 4> const& _v) const noexcept;
        vec<Type, 4> const operator-(vec<Type, 4> const& _v) const noexcept;
        vec<Type, 4> const operator*(vec<Type, 4> const& _v) const noexcept;
        vec<Type, 4> const operator/(vec<Type, 4> const& _v) const noexcept;
        void operator+=(vec<Type, 4> const& _v) noexcept;
        void operator-=(vec<Type, 4> const& _v) noexcept;
        void operator*=(vec<Type, 4> const& _v) noexcept;
        void operator/=(vec<Type, 4> const& _v) noexcept;
        Type& operator[](int _index) noexcept;
        Type const& operator[](int _index) const noexcept;
    };
};

#include "type_vec4.inl"