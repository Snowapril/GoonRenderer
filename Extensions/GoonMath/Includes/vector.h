#pragma once

#include <cmath>

namespace gm 
{
    template <typename T, int Dims>
    class vector 
    {
    public:
        using value_type = T;
        using size_type = int;
        
        //! brief : initialize data as uninitialized array.
        vector() = default;
        
        vector(vector<T, Dims> const& v)
        {
            for (int i = 0; i < Dims; ++i) 
                this->data[i] = v.data[i];
        }
        template <typename U>
        vector(vector<U, Dims> const& v)
        {
            for (int i = 0; i < Dims; ++i)
                this->data[i] = static_cast<T>(v.data[i]);
        }
        vector(T e1)
        {
            for (int i = 0; i < Dims; ++i)
                this->data[i] = e1;
        }
        vector(T *elements)
        {
            for (int i = 0; i < Dims; ++i)
                this->data[i] = elements[i];
        }
        vector(T x, T y)
        {
            static_assert(Dims == 2);
            this->data[0] = x;
            this->data[1] = y;
        }
        vector(T x, T y, T z)
        {
            static_assert(Dims == 3);
            this->data[0] = x;
            this->data[1] = y;
            this->data[2] = z;
        }
        vector(T x, T y, T z, T w)
        {
            static_assert(Dims == 4);
            this->data[0] = x;
            this->data[1] = y;
            this->data[2] = z;
            this->data[3] = w;
        }
        
        inline value_type& operator[](int i) { return data[i] };
        inline value_type const& operator[](int i) const { return data[i] };
    public:
        value_type data[Dims];
    }
    
    template <typename T, int Dims>
    inline bool operator==(vector<T, Dims> const& v1, vector<T, Dims> const& v2)
    {
        for (int i = 0; i < Dims; ++i) 
            if (v1[i] != v2[i]) return false;
        return true;
    }
    template <typename T, int Dims>
    inline bool operator!=(vector<T, Dims> const& v1, vector<T, Dims> const& v2)
    {
        return !(v1 == v2);
    }
    template <typename T, int Dims>
    inline vector<T, Dims> operator-(vector<T, Dims> const& v)
    {
        vector<T, Dims> result;
        for (int i = 0; i < Dims; ++i) 
            result.data[i] = -v.data[i];
        return result;
    }
    template <typename T, int Dims>
    inline vector<T, Dims> operator+(vector<T, Dims> const& v1, vector<T, Dims> const& v2)
    {
        vector<T, Dims> result;
        for (int i = 0; i < Dims; ++i) 
            result.data[i] = v1.data[i] + v2.data[i];
        return result;
    }
    template <typename T, int Dims>
    inline vector<T, Dims> operator-(vector<T, Dims> const& v1, vector<T, Dims> const& v2)
    {
        vector<T, Dims> result;
        for (int i = 0; i < Dims; ++i) 
            result.data[i] = v1.data[i] - v2.data[i];
        return result;
    }
    template <typename T, int Dims>
    inline vector<T, Dims> operator*(vector<T, Dims> const& v1, vector<T, Dims> const& v2)
    {
        vector<T, Dims> result;
        for (int i = 0; i < Dims; ++i) 
            result.data[i] = v1.data[i] * v2.data[i];
        return result;
    }
    template <typename T, int Dims>
    inline vector<T, Dims> operator/(vector<T, Dims> const& v1, vector<T, Dims> const& v2)
    {
        vector<T, Dims> result;
        for (int i = 0; i < Dims; ++i) 
            result.data[i] = v1.data[i] / v2.data[i];
        return result;
    }
};