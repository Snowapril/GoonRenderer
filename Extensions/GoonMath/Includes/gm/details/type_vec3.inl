namespace gm 
{
    template <typename Type>
    vec<Type, 3>::vec() noexcept
        : elements { Type(0), Type(0), Type(0) }
    {
    
    }
    
    template <typename Type>
    vec<Type, 3>::vec(Type _val) noexcept
        : elements { _val, _val, _val }
    {
    
    }
    
    template <typename Type>
    vec<Type, 3>::vec(Type _x, Type _y, Type _z) noexcept
        : x(_x), y(_y), z(_z)
    {
    
    }
    
    template <typename Type>
    vec<Type, 3> const vec<Type, 3>::operator+(vec<Type, 3> const& _v) const noexcept
    {
        vec<Type, 3> result;
        result.x = this->x + _v.x;
        result.y = this->y + _v.y;
        result.z = this->z + _v.z;
        return result;
    }
    
    template <typename Type>
    vec<Type, 3> const vec<Type, 3>::operator-(vec<Type, 3> const& _v) const noexcept
    {
        vec<Type, 3> result;
        result.x = this->x - _v.x;
        result.y = this->y - _v.y;
        result.z = this->z - _v.z;
        return result;
    }
    
    template <typename Type>
    vec<Type, 3> const vec<Type, 3>::operator*(vec<Type, 3> const& _v) const noexcept
    {
        vec<Type, 3> result;
        result.x = this->x * _v.x;
        result.y = this->y * _v.y;
        result.z = this->z * _v.z;
        return result;
    }
    
    template <typename Type>
    vec<Type, 3> const vec<Type, 3>::operator/(vec<Type, 3> const& _v) const noexcept
    {
        vec<Type, 3> result;
        result.x = this->x / _v.x;
        result.y = this->y / _v.y;
        result.z = this->z / _v.z;
        return result;
    }
    
    template <typename Type>
    void vec<Type, 3>::operator+=(vec<Type, 3> const& _v) noexcept
    {
        vec<Type, 3> result;
        result.x += _v.x;
        result.y += _v.y;
        result.z += _v.z;
    }
    
    template <typename Type>
    void vec<Type, 3>::operator-=(vec<Type, 3> const& _v) noexcept
    {
        vec<Type, 3> result;
        result.x -= _v.x;
        result.y -= _v.y;
        result.z -= _v.z;
    }
    
    template <typename Type>
    void vec<Type, 3>::operator*=(vec<Type, 3> const& _v) noexcept
    {
        vec<Type, 3> result;
        result.x *= _v.x;
        result.y *= _v.y;
        result.z *= _v.z;
    }
    
    template <typename Type>
    void vec<Type, 3>::operator/=(vec<Type, 3> const& _v) noexcept
    {
        vec<Type, 3> result;
        result.x /= _v.x;
        result.y /= _v.y;
        result.z /= _v.z;
    }
    
    template <typename Type>
    vec<Type, 3> const vec<Type, 3>::operator+(Type _val) const noexcept
    {
        vec<Type, 3> result;
        result.x = this->x + _val;
        result.y = this->y + _val;
        result.z = this->z + _val;
        return result;
    }
    
    template <typename Type>
    vec<Type, 3> const vec<Type, 3>::operator-(Type _val) const noexcept
    {
        vec<Type, 3> result;
        result.x = this->x - _val;
        result.y = this->y - _val;
        result.z = this->z - _val;
        return result;
    }
    
    template <typename Type>
    vec<Type, 3> const vec<Type, 3>::operator*(Type _val) const noexcept
    {
        vec<Type, 3> result;
        result.x = this->x * _val;
        result.y = this->y * _val;
        result.z = this->z * _val;
        return result;
    }
    
    template <typename Type>
    vec<Type, 3> const vec<Type, 3>::operator/(Type _val) const noexcept
    {
        vec<Type, 3> result;
        float inv_val = 1.0f / _val;
        result.x = this->x * inv_val;
        result.y = this->y * inv_val;
        result.z = this->z * inv_val;
        return result;
    }
    
    template <typename Type>
    void vec<Type, 3>::operator+=(Type _val) noexcept
    {
        this->x += _val;
        this->y += _val;
        this->z += _val;
    }
    
    template <typename Type>
    void vec<Type, 3>::operator-=(Type _val) noexcept
    {
        this->x -= _val;
        this->y -= _val;
        this->z -= _val;
    }
    
    template <typename Type>
    void vec<Type, 3>::operator*=(Type _val) noexcept
    {
        this->x *= _val;
        this->y *= _val;
        this->z *= _val;
    }
    
    template <typename Type>
    void vec<Type, 3>::operator/=(Type _val) noexcept
    {
        float inv_val = 1.0f / _val;
        this->x *= inv_val;
        this->y *= inv_val;
        this->z *= inv_val;
    }
    
    template <typename Type>
    vec<Type, 3> const vec<Type, 3>::operator-() const noexcept
    {
        return vec<Type, 3>(-x, -y, -z);
    }
    
    template <typename Type>
    Type& vec<Type, 3>::operator[](int _index) noexcept
    {
        return static_cast<Type&>(elements[_index]);
    }
    
    template <typename Type>
    Type const& vec<Type, 3>::operator[](int _index) const noexcept
    {
        return static_cast<Type const&>(elements[_index]);
    }
    
    template <typename Type>
    template <typename _OtherType>
    void vec<Type, 3>::operator=(vec<_OtherType, 3> const& _other) noexcept
    {
        this->x = static_cast<Type>(_other.x);
        this->y = static_cast<Type>(_other.y);
        this->z = static_cast<Type>(_other.z);
    }
};