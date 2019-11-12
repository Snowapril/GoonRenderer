#include <iostream>
#include "gm/vec4.h"
#include "gm/property/transform.h"

template <typename Type, int Num>
std::ostream& operator<<(std::ostream& _ostr, gm::vec<Type, Num> const& _v)
{
    for (int i = 0; i < Num - 1; i++)
        _ostr << _v[i] << ", ";
    _ostr << _v[Num - 1];
    return _ostr;
}

int main(void)
{
    gm::vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
    std::cout << "Before clamping  : " << v << std::endl;
    v = gm::clamp(v, gm::vec4(2.0f), gm::vec4(3.0f));
    std::cout << "After clamping   : "  << v << std::endl;
    v = gm::saturate(v);
    std::cout << "After Saturation : " << v << std::endl;
    v = gm::negate(v);
    std::cout << "After negation   : " << v << std::endl;
    v = gm::normalize(v);
    std::cout << "After normalize  : " << v << std::endl;
    
    v *= 512.0f;
    std::cout << "After multiply with 512  : " << v << std::endl;
    
    
    return 0;
}