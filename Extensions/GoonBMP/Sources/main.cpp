#include "gbmp/bmp_image.h"
#include <iostream>

int main(void)
{
    std::cout << "sizeof file header size : "   << sizeof(gbmp::bmp_file_header) << std::endl;
    std::cout << "sizeof bitmap header size : " << sizeof(gbmp::bmp_bitmap_header) << std::endl;
    std::cout << "sizeof color table size : "   << sizeof(gbmp::bmp_color_table) << std::endl;
    
    int width, height;
    unsigned int numChannels;
    auto data = gbmp::gbmp_load_image("../Data/Textures/Box/specular.bmp", &width, &height, &numChannels);
    if (!data) std::cout << "Invalid file format" << std::endl;
    unsigned char* data_ptr = data.value();
    
    return 0;
}