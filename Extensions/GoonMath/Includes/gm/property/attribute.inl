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
    typename Type sum(vec<Type, Num> const& _v) noexcept
    {
        float sum = 0.0f;
        for (Type val : _v.elements)
            sum += val;
        return sum;
    }
    
    
};