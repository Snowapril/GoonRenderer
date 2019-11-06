namespace gm
{
    template <typename Type>
    mat<4, 4, Type>::mat() noexcept
        : value { row_type(), row_type(), row_type(), row_type() }
    {
        
    }
    
    template <typename Type>
    mat<4, 4, Type>::mat(Type _val) noexcept
        : value { row_type(_val), row_type(_val), row_type(_val), row_type(_val) }
    {
        
    }
    
    template <typename Type>
    mat<4, 4, Type>::mat(Type _x0, Type _y0, Type _z0, Type _w0,
                         Type _x1, Type _y1, Type _z1, Type _w1,
                         Type _x2, Type _y2, Type _z2, Type _w2,
                         Type _x3, Type _y3, Type _z3, Type _w3) noexcept
        : value { row_type (_x0, _y0, _z0, _w0), row_type (_x1, _y1, _z1, _w1), 
                  row_type (_x2, _y2, _z2, _w2), row_type (_x3, _y3, _z3, _w3) } 
    {
        
    }
    
    template <typename Type>
    mat<4, 4, Type> const mat<4, 4, Type>::operator+(mat<4, 4, Type> const& _m) const noexcept
    {
        mat<4, 4, Type> result;
        for (int i = 0; i < 4; ++i) 
            result[i] = this->value[i] + _m.value[i];
        return result;
    }
    
    template <typename Type>
    mat<4, 4, Type> const mat<4, 4, Type>::operator-(mat<4, 4, Type> const& _m) const noexcept
    {
        mat<4, 4, Type> result;
        for (int i = 0; i < 4; ++i) 
            result[i] = this->value[i] - _m.value[i];
        return result;
    }
    
    template <typename Type>
    template <int N>
    mat<4, N, Type> const mat<4, 4, Type>::operator*(mat<4, N, Type> const& _m) const noexcept
    {
        
    }
    
    template <typename Type>
    mat<4, 4, Type> const mat<4, 4, Type>::operator/(mat<4, 4, Type> const& _m) const noexcept
    {
        mat<4, 4, Type> result;
        for (int i = 0; i < 4; ++i) 
            result[i] = this->value[i] / _m.value[i];
        return result;
    }
    
    template <typename Type>
    void mat<4, 4, Type>::operator+=(mat<4, 4, Type> const& _m) noexcept
    {
        for (int i = 0; i < 4; ++i) 
            this->value += _m.value[i];
    }
    
    template <typename Type>
    void mat<4, 4, Type>::operator-=(mat<4, 4, Type> const& _m) noexcept
    {
        for (int i = 0; i < 4; ++i) 
            this->value -= _m.value[i];
    }
    
    template <typename Type>
    void mat<4, 4, Type>::operator*=(mat<4, 4, Type> const& _m) noexcept
    {
        for (int i = 0; i < 4; ++i) 
            this->value *= _m.value[i];
    }
    
    template <typename Type>
    void mat<4, 4, Type>::operator/=(mat<4, 4, Type> const& _m) noexcept
    {
        for (int i = 0; i < 4; ++i) 
            this->value /= _m.value[i];
    }
    
    template <typename Type>
    mat<4, 4, Type> const mat<4, 4, Type>::operator+(Type _val) const noexcept
    {
        mat<4, 4, Type> result;
        for (int i = 0; i < 4; ++i) 
            result[i] = this->value[i] + _val;
        return result;
    }
    
    template <typename Type>
    mat<4, 4, Type> const mat<4, 4, Type>::operator-(Type _val) const noexcept
    {
        mat<4, 4, Type> result;
        for (int i = 0; i < 4; ++i) 
            result[i] = this->value[i] - _val;
        return result;
    }
    
    template <typename Type>
    mat<4, 4, Type> const mat<4, 4, Type>::operator*(Type _val) const noexcept
    {
        mat<4, 4, Type> result;
        for (int i = 0; i < 4; ++i) 
            result[i] = this->value[i] * _val;
        return result;
    }
    
    template <typename Type>
    mat<4, 4, Type> const mat<4, 4, Type>::operator/(Type _val) const noexcept
    {
        mat<4, 4, Type> result;
        for (int i = 0; i < 4; ++i) 
            result[i] = this->value[i] / _val;
        return result;
    }
    
    template <typename Type>
    void mat<4, 4, Type>::operator+=(Type _val) noexcept
    {
        for (int i = 0; i < 4; ++i) 
            this->value[i] += _val;
    }
    
    template <typename Type>
    void mat<4, 4, Type>::operator-=(Type _val) noexcept
    {
        for (int i = 0; i < 4; ++i) 
            this->value[i] -= _val;
    }
    
    template <typename Type>
    void mat<4, 4, Type>::operator*=(Type _val) noexcept
    {
        for (int i = 0; i < 4; ++i) 
            this->value[i] *= _val;
    }
    
    template <typename Type>
    void mat<4, 4, Type>::operator/=(Type _val) noexcept
    {
        for (int i = 0; i < 4; ++i) 
            this->value[i] /= _val;
    }
    
    template <typename Type>
    mat<4, 4, Type> const mat<4, 4, Type>::operator-() const noexcept
    {
        mat<4, 4, Type> result;
        for (int i = 0; i < 4; ++i)
            result.value[i] = -this->value[i];
        return result;
    }
    
    template <typename Type>
    row_type& mat<4, 4, Type>::operator[](int _index) noexcept
    {
        return static_cast<row_type&>(this->value[_index]);
    }
    
    template <typename Type>
    row_type const& mat<4, 4, Type>::operator[](int _index) const noexcept
    {
        return static_cast<row_type const&>(this->value[_index]);
    }
    
    
    template <typename Type>
    template <typename _OtherType>
    void mat<4, 4, Type>::operator=(mat<4, 4, _OtherType> const& _other) noexcept
    {
        for (int i = 0; i < 4; ++i)
            this->value[i] = _other.value[i];
    }
};