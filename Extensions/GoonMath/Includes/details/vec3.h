#ifndef GOON_VEC3_H
#define GOON_VEC3_H

namespace gm 
{
    template <typename Type>
    class vec3
    {
    private:
        Type x { Type(0) };
        Type y { Type(0) };
        Type z { Type(0) };
    public:
        vec3() = default;
        vec3(Type _val) noexcept;
        vec3(Type _x, Type _y, Type _z) noexcept;
        vec3<Type> const& operator+(vec3<Type> const& _v) const noexcept;
        vec3<Type> const& operator-(vec3<Type> const& _v) const noexcept;
        vec3<Type> const& operator*(vec3<Type> const& _v) const noexcept;
        vec3<Type> const& operator/(vec3<Type> const& _v) const noexcept;
        void operator+=(vec3<Type> const& _v) noexcept;
        void operator-=(vec3<Type> const& _v) noexcept;
        void operator*=(vec3<Type> const& _v) noexcept;
        void operator/=(vec3<Type> const& _v) noexcept;
    };
}

#endif