namespace gm 
{
    template <typename Type>
    vec<2, Type>::vec() noexcept
        : elements { Type(0), Type(0) }
    {
    
    }
    
    template <typename Type>
    vec<2, Type>::vec(Type _val) noexcept
        : elements { _val, _val }
    {
    
    }
    
    template <typename Type>
    vec<2, Type>::vec(Type _x, Type _y) noexcept
        : x(_x), y(_y)
    {
    
    }
    
    template <typename Type>
    vec<2, Type> const vec<2, Type>::operator+(vec<2, Type> const& _v) const noexcept
    {
        vec<2, Type> result;
        result.x = this->x + _v.x;
        result.y = this->y + _v.y;
        return result;
    }
    
    template <typename Type>
    vec<2, Type> const vec<2, Type>::operator-(vec<2, Type> const& _v) const noexcept
    {
        vec<2, Type> result;
        result.x = this->x - _v.x;
        result.y = this->y - _v.y;
        return result;
    }
    
    template <typename Type>
    vec<2, Type> const vec<2, Type>::operator*(vec<2, Type> const& _v) const noexcept
    {
        vec<2, Type> result;
        result.x = this->x * _v.x;
        result.y = this->y * _v.y;
        return result;
    }
    
    template <typename Type>
    vec<2, Type> const vec<2, Type>::operator/(vec<2, Type> const& _v) const noexcept
    {
        vec<2, Type> result;
        result.x = this->x / _v.x;
        result.y = this->y / _v.y;
        return result;
    }
    
    template <typename Type>
    void vec<2, Type>::operator+=(vec<2, Type> const& _v) noexcept
    {
        result.x += _v.x;
        result.y += _v.y;
    }
    
    template <typename Type>
    void vec<2, Type>::operator-=(vec<2, Type> const& _v) noexcept
    {
        result.x -= _v.x;
        result.y -= _v.y;
    }
    
    template <typename Type>
    void vec<2, Type>::operator*=(vec<2, Type> const& _v) noexcept
    {
        result.x *= _v.x;
        result.y *= _v.y;
    }
    
    template <typename Type>
    void vec<2, Type>::operator/=(vec<2, Type> const& _v) noexcept
    {
        result.x /= _v.x;
        result.y /= _v.y;
    }
    
    template <typename Type>
    vec<2, Type> const vec<2, Type>::operator+(Type _val) const noexcept
    {
        vec<2, Type> result;
        result.x = this->x + _val;
        result.y = this->y + _val;
        return result;
    }
    
    template <typename Type>
    vec<2, Type> const vec<2, Type>::operator-(Type _val) const noexcept;
    {
        vec<2, Type> result;
        result.x = this->x - _val;
        result.y = this->y - _val;
        return result;
    }
    
    template <typename Type>
    vec<2, Type> const vec<2, Type>::operator*(Type _val) const noexcept;
    {
        vec<2, Type> result;
        result.x = this->x * _val;
        result.y = this->y * _val;
        return result;
    }
    
    template <typename Type>
    vec<2, Type> const vec<2, Type>::operator/(Type _val) const noexcept;
    {
        vec<2, Type> result;
        float inv_val = 1.0f / _val;
        result.x = this->x * inv_val;
        result.y = this->y * inv_val;
        return result;
    }
    
    template <typename Type>
    void vec<2, Type>::operator+=(Type _val) noexcept;
    {
        result.x += _val;
        result.y += _val;
    }
    
    template <typename Type>
    void vec<2, Type>::operator-=(Type _val) noexcept;
    {
        result.x -= _val;
        result.y -= _val;
    }
    
    template <typename Type>
    void vec<2, Type>::operator*=(Type _val) noexcept;
    {
        result.x *= _val;
        result.y *= _val;
    }
    
    template <typename Type>
    void vec<2, Type>::operator/=(Type _val) noexcept;
    {
        float inv_val = 1.0f / _val;
        result.x *= inv_val;
        result.y *= inv_val;
    }
    
    template <typename Type>
    vec<2, Type> const vec<2, Type>::operator-() const noexcept
    {
        return vec<2, Type>(-x, -y);
    }
    
    template <typename Type>
    Type& vec<2, Type>::operator[](int _index) noexcept
    {
        return static_cast<Type&>(elements[_index]);
    }
    
    template <typename Type>
    Type const& vec<2, Type>::operator[](int _index) const noexcept
    {
        return static_cast<Type const&>(elements[_index]);
    }
};