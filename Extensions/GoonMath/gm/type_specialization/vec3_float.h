#pragma once

#include "../details/type_vec3.h"

namespace gm
{
    template <typename Type, int Num>
    namespace vec<float, Num> = vec3;
};