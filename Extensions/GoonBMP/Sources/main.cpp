#include "gbmp/bmp_image.h"
#include <iostream>

int main(void)
{
    std::cout << "Size of bmp header : " << sizeof( gbmp::bmp_file_header ) << std::endl;
    return 0;
}