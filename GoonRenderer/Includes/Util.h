#pragma once 

#include "DataType.h"

namespace gr
{
    //! return the max value by comparing two arguments.
    template <typename Type>
    inline Type max(Type const& arg0, Type const& arg1) noexcept
    {
        return arg0 > arg1 ? arg0 : arg1;
    }
    //! return the min value by comparing two arguments.
    template <typename Type>
    inline Type min(Type const& arg0, Type const& arg1) noexcept
    {
        return arg0 < arg1 ? arg0 : arg1;
    }
    //! return the absolute value of the given argument.
    template <typename Type>
    inline Type abs(Type const& arg) noexcept
    {
        return arg >= Type(0) ? arg : -arg;
    }
};

