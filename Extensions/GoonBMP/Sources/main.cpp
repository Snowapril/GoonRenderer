#include "gbmp/bmp_image.h"
#include <iostream>

int main(void)
{
    std::cout << "sizeof file header size : "   << sizeof(gbmp::bmp_file_header) << std::endl;
    std::cout << "sizeof bitmap header size : " << sizeof(gbmp::bmp_bitmap_header) << std::endl;
    std::cout << "sizeof color table size : "   << sizeof(gbmp::bmp_color_table) << std::endl;
    
    int width, height, numChannels;
    unsigned char* data = gbmp::gbmp_load_image("../Data/Textures/Box/albedo.bmp", &width, &height, &numChannels, true);
    if (data == nullptr) std::cout << "Invalid file format" << std::endl;
    
    for (int i = 0; i < width * height; i++) data[3*i] = 255;
    
    bool bSuccess = gbmp::gbmp_write_image("../Data/Textures/Box/test.bmp", data, width, height, numChannels);
    if (!bSuccess) std::cout << "Write bmp file failed" << std::endl;
    
    return 0;
}