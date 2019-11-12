#pragma once


namespace gm 
{
    template <typename Type>
    class vec <Type, 3>
    {
    public:
        union 
        {
            Type elements[3];
            struct { Type x, y, z; };
        };
    public:
        vec() noexcept;
        vec(Type _val) noexcept;
        vec(Type _x, Type _y, Type _z) noexcept;
        vec<Type, 3> const operator+(vec<Type, 3> const& _v) const noexcept;
        vec<Type, 3> const operator-(vec<Type, 3> const& _v) const noexcept;
        vec<Type, 3> const operator*(vec<Type, 3> const& _v) const noexcept;
        vec<Type, 3> const operator/(vec<Type, 3> const& _v) const noexcept;
        void operator+=(vec<Type, 3> const& _v) noexcept;
        void operator-=(vec<Type, 3> const& _v) noexcept;
        void operator*=(vec<Type, 3> const& _v) noexcept;
        void operator/=(vec<Type, 3> const& _v) noexcept;
        vec<Type, 3> const operator+(Type _val) const noexcept;
        vec<Type, 3> const operator-(Type _val) const noexcept;
        vec<Type, 3> const operator*(Type _val) const noexcept;
        vec<Type, 3> const operator/(Type _val) const noexcept;
        void operator+=(Type _val) noexcept;
        void operator-=(Type _val) noexcept;
        void operator*=(Type _val) noexcept;
        void operator/=(Type _val) noexcept;
        vec<Type, 3> const operator-() const noexcept;
        Type& operator[](int _index) noexcept;
        Type const& operator[](int _index) const noexcept;
        
        template <typename _OtherType>
        void operator=(vec<_OtherType, 3> const& _other) noexcept;
    };
};

#include "type_vec3.inl"