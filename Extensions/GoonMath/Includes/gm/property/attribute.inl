#include <cmath>

namespace gm
{
    template <int Num, typename Type>
    float length(vec<Num, Type> const& _v) noexcept
    {
        float squared_sum = 0.0f;
        for (Type val : _v.elements)
            squared_sum += val * val;
        return std::sqrt(squared_sum);
    }
    
    template <int Num, typename Type>
    Type sum(vec<Num, Type> const& _v) noexcept
    {
        float sum = 0.0f;
        for (Type val : _v.elements)
            sum += val;
        return sum;
    }
    
    template <typename Type>
    gm::vec<3, float> barycentric(gm::vec<3, Type> const& _point, gm::vec<3, Type> const& _v0, gm::vec<3, Type> const& _v1, gm::vec<3, Type> const& _v2) noexcept
    {
        Type cy = _v2.y - _v0.y;
        Type cx = _v2.x - _v0.x;
        Type by = _v1.y - _v0.y;
        Type bx = _v1.x - _v0.x;
        
        float w1 = ( _v0.x * cy + (_point.y - _v0.y) * cx - _point.x * cy ) / static_cast<float>(by * cx - bx * cy);
        float w2 = ( _point.y - _v0.y - w1 * by ) / static_cast<float>(cy);
        
        return gm::vec<3, float>(w1, w2, 1.0f - w1 - w2);
    }
};