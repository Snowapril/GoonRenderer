namespace gm 
{
    template <typename Type>
    vec<4, Type>::vec(Type _val) noexcept
        : elements { _val, _val, _val, _val }
    {
    
    }
    
    template <typename Type>
    vec<4, Type>::vec(Type _x, Type _y, Type _z, Type _w) noexcept
        : x(_x), y(_y), z(_z), w(_w)
    {
    
    }
    
    template <typename Type>
    vec<4, Type> const vec<4, Type>::operator+(vec<4, Type> const& _v) const noexcept
    {
        vec<4, Type> result;
        result.x = this->x + _v.x;
        result.y = this->y + _v.y;
        result.z = this->z + _v.z;
        result.w = this->w + _v.w;
        return result;
    }
    
    template <typename Type>
    vec<4, Type> const vec<4, Type>::operator-(vec<4, Type> const& _v) const noexcept
    {
        vec<4, Type> result;
        result.x = this->x - _v.x;
        result.y = this->y - _v.y;
        result.z = this->z - _v.z;
        result.w = this->w - _v.w;
        return result;
    }
    
    template <typename Type>
    vec<4, Type> const vec<4, Type>::operator*(vec<4, Type> const& _v) const noexcept
    {
        vec<4, Type> result;
        result.x = this->x * _v.x;
        result.y = this->y * _v.y;
        result.z = this->z * _v.z;
        result.w = this->w * _v.w;
        return result;
    }
    
    template <typename Type>
    vec<4, Type> const vec<4, Type>::operator/(vec<4, Type> const& _v) const noexcept
    {
        vec<4, Type> result;
        result.x = this->x / _v.x;
        result.y = this->y / _v.y;
        result.z = this->z / _v.z;
        result.w = this->w / _v.w;
        return result;
    }
    
    template <typename Type>
    void vec<4, Type>::operator+=(vec<4, Type> const& _v) noexcept
    {
        vec<4, Type> result;
        result.x += _v.x;
        result.y += _v.y;
        result.z += _v.z;
        result.w += _v.w;
    }
    
    template <typename Type>
    void vec<4, Type>::operator-=(vec<4, Type> const& _v) noexcept
    {
        vec<4, Type> result;
        result.x -= _v.x;
        result.y -= _v.y;
        result.z -= _v.z;
        result.w -= _v.w;
    }
    
    template <typename Type>
    void vec<4, Type>::operator*=(vec<4, Type> const& _v) noexcept
    {
        vec<4, Type> result;    
        result.x *= _v.x;
        result.y *= _v.y;
        result.z *= _v.z;
        result.w *= _v.w;
    }
    
    template <typename Type>
    void vec<4, Type>::operator/=(vec<4, Type> const& _v) noexcept
    {
        vec<4, Type> result;
        result.x /= _v.x;
        result.y /= _v.y;
        result.z /= _v.z;
        result.w /= _v.w;
    }
    
    template <typename Type>
    vec<4, Type> const vec<4, Type>::operator+(Type _val) const noexcept
    {
        vec<4, Type> result;
        result.x = this->x + _val;
        result.y = this->y + _val;
        result.z = this->z + _val;
        result.w = this->w + _val;
        return result;
    }
    
    template <typename Type>
    vec<4, Type> const vec<4, Type>::operator-(Type _val) const noexcept
    {
        vec<4, Type> result;
        result.x = this->x - _val;
        result.y = this->y - _val;
        result.z = this->z - _val;
        result.w = this->w - _val;
        return result;
    }
    
    template <typename Type>
    vec<4, Type> const vec<4, Type>::operator*(Type _val) const noexcept
    {
        vec<4, Type> result;
        result.x = this->x * _val;
        result.y = this->y * _val;
        result.z = this->z * _val;
        result.w = this->w * _val;
        return result;
    }
    
    template <typename Type>
    vec<4, Type> const vec<4, Type>::operator/(Type _val) const noexcept
    {
        vec<4, Type> result;
        float inv_val = 1.0f / _val;
        result.x = this->x * inv_val;
        result.y = this->y * inv_val;
        result.z = this->z * inv_val;
        result.w = this->w * inv_val;
        return result;
    }
    
    template <typename Type>
    void vec<4, Type>::operator+=(Type _val) noexcept
    {
        vec<4, Type> result;
        result.x += _val;
        result.y += _val;
        result.z += _val;
        result.w += _val;
    }
    
    template <typename Type>
    void vec<4, Type>::operator-=(Type _val) noexcept
    {
        vec<4, Type> result;
        result.x -= _val;
        result.y -= _val;
        result.z -= _val;
        result.w -= _val;
    }
    
    template <typename Type>
    void vec<4, Type>::operator*=(Type _val) noexcept
    {
        vec<4, Type> result;
        result.x *= _val;
        result.y *= _val;
        result.z *= _val;
        result.w *= _val;
    }
    
    template <typename Type>
    void vec<4, Type>::operator/=(Type _val) noexcept
    {
        vec<4, Type> result;
        float inv_val = 1.0f / _val;
        result.x *= inv_val;
        result.y *= inv_val;
        result.z *= inv_val;
        result.w *= inv_val;
    }
    
    template <typename Type>
    Type& vec<4, Type>::operator[](int _index) noexcept
    {
        return static_cast<Type&>(elements[_index]);
    }
    
    template <typename Type>
    Type const& vec<4, Type>::operator[](int _index) const noexcept
    {
        return static_cast<Type const&>(elements[_index]);
    }
};