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
    typename Type sum(vec<Num, Type> const& _v) noexcept
    {
        float sum = 0.0f;
        for (Type val : _v.elements)
            sum += val;
        return sum;
    }
    
    
};