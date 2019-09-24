namespace gm
{
    template <typename Type, int Num>
    typename Type dot(vec<Type, Num> const& _v0, vec<Type, Num> const& _v1) noexcept
    {
        Type dot_sum = Type(0);
        for (int i = 0; i < Num; i++)
            dot_sum += _v0.elements[i] * _v1.elements[i];
        return dot_sum;
    }
};