namespace gm 
{
    template <typename Type>
    vec<Type, 2>::vec() noexcept
        : elements { Type(0), Type(0) }
    {
    
    }
    
    template <typename Type>
    vec<Type, 2>::vec(Type _val) noexcept
        : elements { _val, _val }
    {
    
    }
    
    template <typename Type>
    vec<Type, 2>::vec(Type _x, Type _y) noexcept
        : x(_x), y(_y)
    {
    
    }
    
    template <typename Type>
    vec<Type, 2> const vec<Type, 2>::operator+(vec<Type, 2> const& _v) const noexcept
    {
        vec<Type, 2> result;
        result.x = this->x + _v.x;
        result.y = this->y + _v.y;
        return result;
    }
    
    template <typename Type>
    vec<Type, 2> const vec<Type, 2>::operator-(vec<Type, 2> const& _v) const noexcept
    {
        vec<Type, 2> result;
        result.x = this->x - _v.x;
        result.y = this->y - _v.y;
        return result;
    }
    
    template <typename Type>
    vec<Type, 2> const vec<Type, 2>::operator*(vec<Type, 2> const& _v) const noexcept
    {
        vec<Type, 2> result;
        result.x = this->x * _v.x;
        result.y = this->y * _v.y;
        return result;
    }
    
    template <typename Type>
    vec<Type, 2> const vec<Type, 2>::operator/(vec<Type, 2> const& _v) const noexcept
    {
        vec<Type, 2> result;
        result.x = this->x / _v.x;
        result.y = this->y / _v.y;
        return result;
    }
    
    template <typename Type>
    void vec<Type, 2>::operator+=(vec<Type, 2> const& _v) noexcept
    {
        vec<Type, 2> result;
        result.x += _v.x;
        result.y += _v.y;
    }
    
    template <typename Type>
    void vec<Type, 2>::operator-=(vec<Type, 2> const& _v) noexcept
    {
        vec<Type, 2> result;
        result.x -= _v.x;
        result.y -= _v.y;
    }
    
    template <typename Type>
    void vec<Type, 2>::operator*=(vec<Type, 2> const& _v) noexcept
    {
        vec<Type, 2> result;
        result.x *= _v.x;
        result.y *= _v.y;
    }
    
    template <typename Type>
    void vec<Type, 2>::operator/=(vec<Type, 2> const& _v) noexcept
    {
        vec<Type, 2> result;
        result.x /= _v.x;
        result.y /= _v.y;
    }
    
    template <typename Type>
    vec<Type, 2> const vec<Type, 2>::operator+(Type _val) const noexcept
    {
        vec<Type, 2> result;
        result.x = this->x + _val;
        result.y = this->y + _val;
        return result;
    }
    
    template <typename Type>
    vec<Type, 2> const vec<Type, 2>::operator-(Type _val) const noexcept
    {
        vec<Type, 2> result;
        result.x = this->x - _val;
        result.y = this->y - _val;
        return result;
    }
    
    template <typename Type>
    vec<Type, 2> const vec<Type, 2>::operator*(Type _val) const noexcept
    {
        vec<Type, 2> result;
        result.x = this->x * _val;
        result.y = this->y * _val;
        return result;
    }
    
    template <typename Type>
    vec<Type, 2> const vec<Type, 2>::operator/(Type _val) const noexcept
    {
        vec<Type, 2> result;
        float inv_val = 1.0f / _val;
        result.x = this->x * inv_val;
        result.y = this->y * inv_val;
        return result;
    }
    
    template <typename Type>
    void vec<Type, 2>::operator+=(Type _val) noexcept
    {
        this->x += _val;
        this->y += _val;
    }
    
    template <typename Type>
    void vec<Type, 2>::operator-=(Type _val) noexcept
    {
        this->x -= _val;
        this->y -= _val;
    }
    
    template <typename Type>
    void vec<Type, 2>::operator*=(Type _val) noexcept
    {
        this->x *= _val;
        this->y *= _val;
    }
    
    template <typename Type>
    void vec<Type, 2>::operator/=(Type _val) noexcept
    {
        float inv_val = 1.0f / _val;
        this->x *= inv_val;
        this->y *= inv_val;
    }
    
    template <typename Type>
    vec<Type, 2> const vec<Type, 2>::operator-() const noexcept
    {
        return vec<Type, 2>(-x, -y);
    }
    
    template <typename Type>
    Type& vec<Type, 2>::operator[](int _index) noexcept
    {
        return static_cast<Type&>(elements[_index]);
    }
    
    template <typename Type>
    Type const& vec<Type, 2>::operator[](int _index) const noexcept
    {
        return static_cast<Type const&>(elements[_index]);
    }
    
    template <typename Type>
    template <typename _OtherType>
    void vec<Type, 2>::operator=(vec<_OtherType, 2> const& _other) noexcept
    {
        this->x = static_cast<Type>(_other.x);
        this->y = static_cast<Type>(_other.y);
    }
};