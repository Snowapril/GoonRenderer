#pragma once

#include "type_vec_base.h"

namespace gm 
{
    template <typename Type>
    class vec <2, Type> : std::true_type
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
        vec<2, Type> const operator+(vec<2, Type> const& _v) const noexcept;
        vec<2, Type> const operator-(vec<2, Type> const& _v) const noexcept;
        vec<2, Type> const operator*(vec<2, Type> const& _v) const noexcept;
        vec<2, Type> const operator/(vec<2, Type> const& _v) const noexcept;
        void operator+=(vec<2, Type> const& _v) noexcept;
        void operator-=(vec<2, Type> const& _v) noexcept;
        void operator*=(vec<2, Type> const& _v) noexcept;
        void operator/=(vec<2, Type> const& _v) noexcept;
        vec<2, Type> const operator+(Type _val) const noexcept;
        vec<2, Type> const operator-(Type _val) const noexcept;
        vec<2, Type> const operator*(Type _val) const noexcept;
        vec<2, Type> const operator/(Type _val) const noexcept;
        void operator+=(Type _val) noexcept;
        void operator-=(Type _val) noexcept;
        void operator*=(Type _val) noexcept;
        void operator/=(Type _val) noexcept;
        vec<2, Type> const operator-() const noexcept;
        Type& operator[](int _index) noexcept;
        Type const& operator[](int _index) const noexcept;
    };
};

#include "type_vec2.inl"