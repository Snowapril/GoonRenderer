#pragma once

#include <type_traits>

namespace gr
{
    template <int NumRow = 4, int NumCol = 4, typename Type>
    class mat : std::false_type {};
};