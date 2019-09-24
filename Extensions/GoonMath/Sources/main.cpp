#include <iostream>
#include "gm/vec4.h"
#include "gm/property/transform.h"

template <int Num, typename Type>
std::ostream& operator<<(std::ostream& _ostr, gm::vec<Num, Type> const& _v)
{
    for (int i = 0; i < Num - 1; i++)
        _ostr << _v[i] << ", ";
    _ostr << _v[Num - 1];
}

int main(void)
{
    gm::vec4 v(3.0f);
    std::cout << v << std::endl;
    
    return 0;
}