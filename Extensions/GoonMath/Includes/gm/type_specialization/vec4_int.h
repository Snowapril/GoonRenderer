#pragma once

#include "../details/type_vec4.h"

namespace gm
{
    template <typename Type, int Num>
    namespace vec<int, Num> = ivec4;
};