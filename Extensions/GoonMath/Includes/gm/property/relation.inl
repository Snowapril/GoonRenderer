namespace gm
{
    template <int Num, typename Type>
    typename Type dot(vec<Num, Type> const& _v0, vec<Num, Type> const& _v1) noexcept
    {
        Type dot_sum = Type(0);
        for (int i = 0; i < Num; i++)
            dot_sum += _v0.elements[i] * _v1.elements[i];
        return dot_sum;
    }
    
    template <typename Type>
    gm::vec<3, Type> cross(gm::vec<3, Type> const& _v0, gm::vec<3, Type> const& _v1) noexcept
    {
        return gm::vec<3, Type>(
            _v0.y * _v1.z - _v0.z * _v1.y, 
            _v0.z * _v1.x - _v0.x * _v1.z,
            _v0.x * _v1.y - _v0.y * _v1.x
        );
    }   
};