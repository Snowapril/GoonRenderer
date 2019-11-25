#include <iostream>
#include "gm/vector.h"
#include "gm/simd/simd4f.h"

template <typename T, int Dims>
std::ostream& operator<<(std::ostream& ostr, gm::vector<T, Dims> const& v)
{
    for (int i = 0 ; i < Dims - 1; ++i)
        ostr << v.data[i] << ", ";
    ostr << v.data[Dims - 1];
    return ostr;
}

std::ostream& operator<<(std::ostream& ostr, gm::simd4f const& s)
{
    ostr << simd4f_get_x(s) << ", "
         << simd4f_get_y(s) << ", "
         << simd4f_get_y(s) << ", " 
         << simd4f_get_y(s);
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
    
    v2 *= 1024.0f;
    std::cout << v2 << std::endl;
    
    gm::simd4f s1(1), s2(1);
    std::cout << (s1 == s2) << std::endl;
    s1 += s2;
    std::cout << s1 << std::endl;
    
    gm::vector<int, 4> v3(3);
    v3 += v1;
    
    return 0;
}
