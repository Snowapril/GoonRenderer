#pragma once 

#include "DataType.h"


namespace gr
{
    template <typename Type>
    inline Type max(Type const& arg0, Type const& arg1) noexcept
    {
        return arg0 > arg1 ? arg0 : arg1;
    }
    
    template <typename Type>
    inline Type min(Type const& arg0, Type const& arg1) noexcept
    {
        return arg0 < arg1 ? arg0 : arg1;
    }
    
    template <typename Type>
    inline Type abs(Type const& arg) noexcept
    {
        return arg >= Type(0) ? arg : -arg;
    }
};

