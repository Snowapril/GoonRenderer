#include <iostream>
#include "Colorbuffer.h"

using namespace gr;

int main(void)
{
    std::cout << "This is test for checking build-status" << std::endl;
    
    Colorbuffer buffer(256, 256, 3);
    buffer.fillColor(30, 230, 180, 50, GRColor::Red);
    buffer.fillColor(100, 190, 250, 100, GRColor::White);
    buffer.writeBMPFile("../Data/Textures/Box/rendered_image.bmp");
    
    return 0;
}