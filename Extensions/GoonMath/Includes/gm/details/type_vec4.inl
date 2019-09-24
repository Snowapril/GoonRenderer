namespace gm 
{
    template <typename Type>
    vec<Type, 4>::vec(Type _val) noexcept
        : elements { _val, _val, _val, _val }
    {
    
    }
    
    template <typename Type>
    vec<Type, 4>::vec(Type _x, Type _y, Type _z, Type _w) noexcept
        : x(_x), y(_y), z(_z), w(_w)
    {
    
    }
    
    template <typename Type>
    vec<Type, 4> const vec<Type, 4>::operator+(vec<Type, 4> const& _v) const noexcept
    {
        vec<Type, 4> result;
        result.x = this->x + _v.x;
        result.y = this->y + _v.y;
        result.z = this->z + _v.z;
        result.w = this->w + _v.w;
        return result;
    }
    
    template <typename Type>
    vec<Type, 4> const vec<Type, 4>::operator-(vec<Type, 4> const& _v) const noexcept
    {
        vec<Type, 4> result;
        result.x = this->x - _v.x;
        result.y = this->y - _v.y;
        result.z = this->z - _v.z;
        result.w = this->w - _v.w;
        return result;
    }
    
    template <typename Type>
    vec<Type, 4> const vec<Type, 4>::operator*(vec<Type, 4> const& _v) const noexcept
    {
        vec<Type, 4> result;
        result.x = this->x * _v.x;
        result.y = this->y * _v.y;
        result.z = this->z * _v.z;
        result.w = this->w * _v.w;
        return result;
    }
    
    template <typename Type>
    vec<Type, 4> const vec<Type, 4>::operator/(vec<Type, 4> const& _v) const noexcept
    {
        vec<Type, 4> result;
        result.x = this->x / _v.x;
        result.y = this->y / _v.y;
        result.z = this->z / _v.z;
        result.w = this->w / _v.w;
        return result;
    }
    
    template <typename Type>
    void vec<Type, 4>::operator+=(vec<Type, 4> const& _v) noexcept
    {
        result.x += _v.x;
        result.y += _v.y;
        result.z += _v.z
        result.w += _v.w;
    }
    
    template <typename Type>
    void vec<Type, 4>::operator-=(vec<Type, 4> const& _v) noexcept
    {
        result.x -= _v.x;
        result.y -= _v.y;
        result.z -= _v.z;
        result.w -= _v.w;
    }
    
    template <typename Type>
    void vec<Type, 4>::operator*=(vec<Type, 4> const& _v) noexcept
    {
        result.x *= _v.x;
        result.y *= _v.y;
        result.z *= _v.z
        result.w *= _v.w;
    }
    
    template <typename Type>
    void vec<Type, 4>::operator/=(vec<Type, 4> const& _v) noexcept
    {
        result.x /= _v.x;
        result.y /= _v.y;
        result.z /= _v.z;
        result.w /= _v.w;
    }
    
    template <typename Type>
    vec<Type, 4> const vec<Type, 4>::operator+(Type _val) const noexcept
    {
        vec<Type, 4> result;
        result.x = this->x + _val;
        result.y = this->y + _val;
        result.z = this->z + _val;
        result.w = this->w + _val;
        return result;
    }
    
    template <typename Type>
    vec<Type, 4> const vec<Type, 4>::operator-(Type _val) const noexcept;
    {
        vec<Type, 4> result;
        result.x = this->x - _val;
        result.y = this->y - _val;
        result.z = this->z - _val;
        result.w = this->w - _val;
        return result;
    }
    
    template <typename Type>
    vec<Type, 4> const vec<Type, 4>::operator*(Type _val) const noexcept;
    {
        vec<Type, 4> result;
        result.x = this->x * _val;
        result.y = this->y * _val;
        result.z = this->z * _val;
        result.w = this->w * _val;
        return result;
    }
    
    template <typename Type>
    vec<Type, 4> const vec<Type, 4>::operator/(Type _val) const noexcept;
    {
        vec<Type, 4> result;
        float inv_val = 1.0f / _val;
        result.x = this->x * inv_val;
        result.y = this->y * inv_val;
        result.z = this->z * inv_val;
        result.w = this->w * inv_val;
        return result;
    }
    
    template <typename Type>
    void vec<Type, 4>::operator+=(Type _val) noexcept;
    {
        result.x += _val;
        result.y += _val;
        result.z += _val;
        result.w += _val;
    }
    
    template <typename Type>
    void vec<Type, 4>::operator-=(Type _val) noexcept;
    {
        result.x -= _val;
        result.y -= _val;
        result.z -= _val;
        result.w -= _val;
    }
    
    template <typename Type>
    void vec<Type, 4>::operator*=(Type _val) noexcept;
    {
        result.x *= _val;
        result.y *= _val;
        result.z *= _val;
        result.w *= _val;
    }
    
    template <typename Type>
    void vec<Type, 4>::operator/=(Type _val) noexcept;
    {
        float inv_val = 1.0f / _val;
        result.x *= inv_val;
        result.y *= inv_val;
        result.z *= inv_val;
        result.w *= inv_val;
    }
    
    template <typename Type>
    Type& vec<Type, 4>::operator[](int _index) noexcept
    {
        return static_cast<Type&>(elements[_index]);
    }
    
    template <typename Type>
    Type const& vec<Type, 4>::operator[](int _index) const noexcept
    {
        return static_cast<Type const&>(elements[_index]);
    }
};