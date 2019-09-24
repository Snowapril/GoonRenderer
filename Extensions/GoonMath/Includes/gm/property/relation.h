#pragma once

#include "../details/type_vec_base.h"

namespace gm
{
    template <int Num, typename Type>
    typename Type dot(vec<Num, Type> const& _v0, vec<Num, Type> const& _v1) noexcept;
};

#include "relation.inl"