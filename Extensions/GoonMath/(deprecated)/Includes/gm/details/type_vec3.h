#pragma once


namespace gm 
{
    template <typename Type>
    struct vec <3, Type>
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
        vec<3, Type> const operator-() const noexcept;
        Type& operator[](int _index) noexcept;
        Type const& operator[](int _index) const noexcept;
        
        template <typename _OtherType>
        void operator=(vec<3, _OtherType> const& _other) noexcept;
    };
};

#include "type_vec3.inl"