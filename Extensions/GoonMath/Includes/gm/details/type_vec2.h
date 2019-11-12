#pragma once

#include "platform.h"

namespace gm 
{
    template <typename Type>
    class vec <Type, 2>
    {
    public:
        union 
        {
            Type elements[2];
            struct { Type x, y; };
        };
    public:
        vec() noexcept;
        vec(Type _val) noexcept;
        vec(Type _x, Type _y) noexcept;
        vec<Type, 2> const operator+(vec<Type, 2> const& _v) const noexcept;
        vec<Type, 2> const operator-(vec<Type, 2> const& _v) const noexcept;
        vec<Type, 2> const operator*(vec<Type, 2> const& _v) const noexcept;
        vec<Type, 2> const operator/(vec<Type, 2> const& _v) const noexcept;
        void operator+=(vec<Type, 2> const& _v) noexcept;
        void operator-=(vec<Type, 2> const& _v) noexcept;
        void operator*=(vec<Type, 2> const& _v) noexcept;
        void operator/=(vec<Type, 2> const& _v) noexcept;
        vec<Type, 2> const operator+(Type _val) const noexcept;
        vec<Type, 2> const operator-(Type _val) const noexcept;
        vec<Type, 2> const operator*(Type _val) const noexcept;
        vec<Type, 2> const operator/(Type _val) const noexcept;
        void operator+=(Type _val) noexcept;
        void operator-=(Type _val) noexcept;
        void operator*=(Type _val) noexcept;
        void operator/=(Type _val) noexcept;
        vec<Type, 2> const operator-() const noexcept;
        Type& operator[](int _index) noexcept;
        Type const& operator[](int _index) const noexcept;
        
        template <typename _OtherType>
        void operator=(vec<_OtherType, 2> const& _other) noexcept;
    };
};

#include "type_vec2.inl"