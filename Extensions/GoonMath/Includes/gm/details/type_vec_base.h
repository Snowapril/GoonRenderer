#pragma once
#include <type_traits>

namespace gm 
{
    template <int Num, typename Type>
    class vec : std::false_type {};  
};