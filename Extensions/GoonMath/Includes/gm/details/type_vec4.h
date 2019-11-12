#pragma once

#include "platform.h"

namespace gm 
{
    template <typename Type>
    class vec <Type, 4>
    {
    public:
        union 
        {
            Type elements[4];
            struct { Type x, y, z, w; };
        };
    public:
        vec() noexcept;
        vec(Type _val) noexcept;
        vec(Type _x, Type _y, Type _z, Type _w) noexcept;
        vec<Type, 4> const operator+(vec<Type, 4> const& _v) const noexcept;
        vec<Type, 4> const operator-(vec<Type, 4> const& _v) const noexcept;
        vec<Type, 4> const operator*(vec<Type, 4> const& _v) const noexcept;
        vec<Type, 4> const operator/(vec<Type, 4> const& _v) const noexcept;
        void operator+=(vec<Type, 4> const& _v) noexcept;
        void operator-=(vec<Type, 4> const& _v) noexcept;
        void operator*=(vec<Type, 4> const& _v) noexcept;
        void operator/=(vec<Type, 4> const& _v) noexcept;
        vec<Type, 4> const operator+(Type _val) const noexcept;
        vec<Type, 4> const operator-(Type _val) const noexcept;
        vec<Type, 4> const operator*(Type _val) const noexcept;
        vec<Type, 4> const operator/(Type _val) const noexcept;
        void operator+=(Type _val) noexcept;
        void operator-=(Type _val) noexcept;
        void operator*=(Type _val) noexcept;
        void operator/=(Type _val) noexcept;
        vec<Type, 4> const operator-() const noexcept;
        Type& operator[](int _index) noexcept;
        Type const& operator[](int _index) const noexcept;
        
        template <typename _OtherType>
        void operator=(vec<_OtherType, 4> const& _other) noexcept;
    };
};

#include "type_vec4.inl"