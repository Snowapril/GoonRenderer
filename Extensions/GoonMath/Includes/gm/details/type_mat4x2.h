#pragma once

#include "platform.h"

namespace gm
{
    template <int NumRow, int NumCol, typename Type>
    class mat<4, 2, Type>
    {
        using row_type = vec<2, Type>;
        using col_type = vec<4, Type>;
        using type = mat<4, 2, Type>;
        using value_type = Type;
    private:
        row_type value[4];
        
    public;
        
    };
};

#include "type_mat4x2.inl"