#pragma once

#include "type_mat_base.h"
#include "type_vec4.h"

namespace gm
{
template <typename Type>
class mat <4, 4, Type> : std::true_type
{
    using row_type = vec<4, Type>;
    using col_type = vec<4, Type>;
    using type = mat<4, 4, Type>;
    using value_type = Type;
private:
    row_type value[4];
    
public:
    mat() noexcept;
    mat(Type _val) noexcept;
    mat(Type _x0, Type _y0, Type _z0, Type _w0,
        Type _x1, Type _y1, Type _z1, Type _w1,
        Type _x2, Type _y2, Type _z2, Type _w2,
        Type _x3, Type _y3, Type _z3, Type _w3) noexcept;
    mat<4, 4, Type> const operator+(mat<4, 4, Type> const& _m) const noexcept;
    mat<4, 4, Type> const operator-(mat<4, 4, Type> const& _m) const noexcept;
    template <int N>
    mat<4, N, Type> const operator*(mat<4, N, Type> const& _m) const noexcept;
    mat<4, 4, Type> const operator/(mat<4, 4, Type> const& _m) const noexcept;
    void operator+=(mat<4, 4, Type> const& _m) noexcept;
    void operator-=(mat<4, 4, Type> const& _m) noexcept;
    void operator*=(mat<4, 4, Type> const& _m) noexcept;
    void operator/=(mat<4, 4, Type> const& _m) noexcept;
    mat<4, 4, Type> const operator+(Type _val) const noexcept;
    mat<4, 4, Type> const operator-(Type _val) const noexcept;
    mat<4, 4, Type> const operator*(Type _val) const noexcept;
    mat<4, 4, Type> const operator/(Type _val) const noexcept;
    void operator+=(Type _val) noexcept;
    void operator-=(Type _val) noexcept;
    void operator*=(Type _val) noexcept;
    void operator/=(Type _val) noexcept;
    mat<4, 4, Type> const operator-() const noexcept;
    typename row_type& operator[](int _index) noexcept;
    typename row_type const& operator[](int _index) const noexcept;
    
    template <typename _OtherType>
    void operator=(mat<4, 4, _OtherType> const& _other) noexcept;
};
};

#include "type_mat4x4.inl"