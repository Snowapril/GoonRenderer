#include <iostream>
#include "gm/vector.h"

template <typename T, int Dims>
std::ostream& operator<<(std::ostream& ostr, gm::vector<T, Dims> const& v)
{
    for (int i = 0 ; i < Dims - 1; ++i)
        ostr << v.data[i] << ", ";
    ostr << v.data[Dims - 1];
    return ostr;
}

int main(int argc, char* argv[])
{
    gm::vector<float, 4> v1(1, 10, -3, -6), v2(3);
    
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << clamp(v1, -4.0f, 5.0f) << std::endl;
    std::cout << saturate(v1) << std::endl;
    std::cout << dot(v1, v2) << std::endl;
    return 0;
}