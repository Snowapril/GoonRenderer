namespace gm 
{
    template <typename Type>
    vec<3, Type>::vec() noexcept
        : elements { Type(0), Type(0), Type(0) }
    {
    
    }
    
    template <typename Type>
    vec<3, Type>::vec(Type _val) noexcept
        : elements { _val, _val, _val }
    {
    
    }
    
    template <typename Type>
    vec<3, Type>::vec(Type _x, Type _y, Type _z) noexcept
        : x(_x), y(_y), z(_z)
    {
    
    }
    
    template <typename Type>
    vec<3, Type> const vec<3, Type>::operator+(vec<3, Type> const& _v) const noexcept
    {
        vec<3, Type> result;
        result.x = this->x + _v.x;
        result.y = this->y + _v.y;
        result.z = this->z + _v.z;
        return result;
    }
    
    template <typename Type>
    vec<3, Type> const vec<3, Type>::operator-(vec<3, Type> const& _v) const noexcept
    {
        vec<3, Type> result;
        result.x = this->x - _v.x;
        result.y = this->y - _v.y;
        result.z = this->z - _v.z;
        return result;
    }
    
    template <typename Type>
    vec<3, Type> const vec<3, Type>::operator*(vec<3, Type> const& _v) const noexcept
    {
        vec<3, Type> result;
        result.x = this->x * _v.x;
        result.y = this->y * _v.y;
        result.z = this->z * _v.z;
        return result;
    }
    
    template <typename Type>
    vec<3, Type> const vec<3, Type>::operator/(vec<3, Type> const& _v) const noexcept
    {
        vec<3, Type> result;
        result.x = this->x / _v.x;
        result.y = this->y / _v.y;
        result.z = this->z / _v.z;
        return result;
    }
    
    template <typename Type>
    void vec<3, Type>::operator+=(vec<3, Type> const& _v) noexcept
    {
        vec<3, Type> result;
        result.x += _v.x;
        result.y += _v.y;
        result.z += _v.z;
    }
    
    template <typename Type>
    void vec<3, Type>::operator-=(vec<3, Type> const& _v) noexcept
    {
        vec<3, Type> result;
        result.x -= _v.x;
        result.y -= _v.y;
        result.z -= _v.z;
    }
    
    template <typename Type>
    void vec<3, Type>::operator*=(vec<3, Type> const& _v) noexcept
    {
        vec<3, Type> result;
        result.x *= _v.x;
        result.y *= _v.y;
        result.z *= _v.z;
    }
    
    template <typename Type>
    void vec<3, Type>::operator/=(vec<3, Type> const& _v) noexcept
    {
        vec<3, Type> result;
        result.x /= _v.x;
        result.y /= _v.y;
        result.z /= _v.z;
    }
    
    template <typename Type>
    vec<3, Type> const vec<3, Type>::operator+(Type _val) const noexcept
    {
        vec<3, Type> result;
        result.x = this->x + _val;
        result.y = this->y + _val;
        result.z = this->z + _val;
        return result;
    }
    
    template <typename Type>
    vec<3, Type> const vec<3, Type>::operator-(Type _val) const noexcept
    {
        vec<3, Type> result;
        result.x = this->x - _val;
        result.y = this->y - _val;
        result.z = this->z - _val;
        return result;
    }
    
    template <typename Type>
    vec<3, Type> const vec<3, Type>::operator*(Type _val) const noexcept
    {
        vec<3, Type> result;
        result.x = this->x * _val;
        result.y = this->y * _val;
        result.z = this->z * _val;
        return result;
    }
    
    template <typename Type>
    vec<3, Type> const vec<3, Type>::operator/(Type _val) const noexcept
    {
        vec<3, Type> result;
        float inv_val = 1.0f / _val;
        result.x = this->x * inv_val;
        result.y = this->y * inv_val;
        result.z = this->z * inv_val;
        return result;
    }
    
    template <typename Type>
    void vec<3, Type>::operator+=(Type _val) noexcept
    {
        this->x += _val;
        this->y += _val;
        this->z += _val;
    }
    
    template <typename Type>
    void vec<3, Type>::operator-=(Type _val) noexcept
    {
        this->x -= _val;
        this->y -= _val;
        this->z -= _val;
    }
    
    template <typename Type>
    void vec<3, Type>::operator*=(Type _val) noexcept
    {
        this->x *= _val;
        this->y *= _val;
        this->z *= _val;
    }
    
    template <typename Type>
    void vec<3, Type>::operator/=(Type _val) noexcept
    {
        float inv_val = 1.0f / _val;
        this->x *= inv_val;
        this->y *= inv_val;
        this->z *= inv_val;
    }
    
    template <typename Type>
    vec<3, Type> const vec<3, Type>::operator-() const noexcept
    {
        return vec<3, Type>(-x, -y, -z);
    }
    
    template <typename Type>
    Type& vec<3, Type>::operator[](int _index) noexcept
    {
        return static_cast<Type&>(elements[_index]);
    }
    
    template <typename Type>
    Type const& vec<3, Type>::operator[](int _index) const noexcept
    {
        return static_cast<Type const&>(elements[_index]);
    }
    
    template <typename Type>
    template <typename _OtherType>
    void vec<3, Type>::operator=(vec<3, _OtherType> const& _other) noexcept
    {
        this->x = static_cast<Type>(_other.x);
        this->y = static_cast<Type>(_other.y);
        this->z = static_cast<Type>(_other.z);
    }
};