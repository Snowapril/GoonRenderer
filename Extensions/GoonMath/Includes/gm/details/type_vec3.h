#pragma once

#include "type_vec_base.h"

namespace gm 
{
    template <typename Type>
    class vec <3, Type> : std::true_type
    {
    public:
        union 
        {
            Type elements[3];
            struct 
            { 
                Type x { Type(0) };
                Type y { Type(0) };
                Type z { Type(0) };
            };
        };
    public:
        vec() = default;
        vec(Type _val) noexcept;
        vec(Type _x, Type _y, Type _z) noexcept;
        vec<3, Type> const operator+(vec<3, Type> const& _v) const noexcept;
        vec<3, Type> const operator-(vec<3, Type> const& _v) const noexcept;
        vec<3, Type> const operator*(vec<3, Type> const& _v) const noexcept;
        vec<3, Type> const operator/(vec<3, Type> const& _v) const noexcept;
        void operator+=(vec<3, Type> const& _v) noexcept;
        void operator-=(vec<3, Type> const& _v) noexcept;
        void operator*=(vec<3, Type> const& _v) noexcept;
        void operator/=(vec<3, Type> const& _v) noexcept;
        vec<3, Type> const operator+(Type _val) const noexcept;
        vec<3, Type> const operator-(Type _val) const noexcept;
        vec<3, Type> const operator*(Type _val) const noexcept;
        vec<3, Type> const operator/(Type _val) const noexcept;
        void operator+=(Type _val) noexcept;
        void operator-=(Type _val) noexcept;
        void operator*=(Type _val) noexcept;
        void operator/=(Type _val) noexcept;
        Type& operator[](int _index) noexcept;
        Type const& operator[](int _index) const noexcept;
    };
};

#include "type_vec3.inl"