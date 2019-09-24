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
};