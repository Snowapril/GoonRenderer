#include <cmath>

namespace gm
{
    template <typename Type, int Num>
    float length(vec<Type, Num> const& _v) noexcept
    {
        float squared_sum = 0.0f;
        for (Type val : _v.elements)
            squared_sum += val * val;
        return std::sqrt(squared_sum);
    }
    
    template <typename Type, int Num>
    Type sum(vec<Type, Num> const& _v) noexcept
    {
        float sum = 0.0f;
        for (Type val : _v.elements)
            sum += val;
        return sum;
    }
    
    template <typename Type>
    gm::vec<float, 3> barycentric(gm::vec<Type, 3> const& _point, gm::vec<Type, 3> const& _v0, gm::vec<Type, 3> const& _v1, gm::vec<Type, 3> const& _v2) noexcept
    {
        Type cy = _v2.y - _v0.y;
        Type cx = _v2.x - _v0.x;
        Type by = _v1.y - _v0.y;
        Type bx = _v1.x - _v0.x;
        
        float w1 = ( _v0.x * cy + (_point.y - _v0.y) * cx - _point.x * cy ) / static_cast<float>(by * cx - bx * cy);
        float w2 = ( _point.y - _v0.y - w1 * by ) / static_cast<float>(cy);
        
        return gm::vec<float, 3>(w1, w2, 1.0f - w1 - w2);
    }
};