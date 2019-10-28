#pragma once

#include <type_traits>

namespace gr
{
    template <int NumRow, int NumCol, typename Type>
    class mat : std::false_type {};
};