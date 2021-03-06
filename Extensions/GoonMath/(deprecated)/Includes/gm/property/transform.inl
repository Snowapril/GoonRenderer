#include "attribute.h"

namespace gm
{
    template <typename Type>
    Type const lerp(Type const& _t1, Type const& _t2, float _p) noexcept
    {
        return _t1 * (1.0f - _p) + _t2 * _p;
    }

    template <size_t Num, typename Type>
    vec<Num, Type> const clamp(vec<Num, Type> const& _target, vec<Num, Type> const& _min, vec<Num, Type> const& _max) noexcept
    {
        vec<Num, Type> result;
        for (int i = 0; i < Num; i++)
        {
            if      (_target[i] < _min[i]) result[i] = _min[i];
            else if (_target[i] > _max[i]) result[i] = _max[i];
            else                           result[i] = _target[i];
        }
        return result;
    }
    
    template <typename Type>
    Type const clamp(Type const& _target, Type const& _min, Type const& _max) noexcept
    {
        if      (_target < _min) return _min;
        else if (_target > _max) return _max;
        else                     return _target;
    }
    
    template <typename Type>
    Type const saturate(Type const& _target) noexcept
    {
        Type result = clamp(_target, Type(0.0f), Type(1.0f));
        return result;
    }
    
    template <typename Type>
    Type const negate(Type const& _target) noexcept
    {
        return -_target;
    }
    
    template <size_t Num, typename Type>
    vec<Num, Type> const normalize(vec<Num, Type> const& _v) noexcept
    {
        float len = length(_v);
        float len_inv = 1 / len;
        vec<Num, Type> result = _v * len_inv;
        return result;
    }
    
    template <size_t Num, typename Type>
    vec<Num, Type> const reflect(vec<Num, Type> const& _v, vec<Num, Type> const& _axis) noexcept
    {
        vec<Num, Type> axis = normalize(_axis);
        vec<Num, Type> result = _v - 2 * dot(_v, axis) * axis;
        
        return result;
    }
};
