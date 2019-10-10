#include <iostream>
#include "Buffer.h"
#include "MeshRenderer.h"

using namespace gr;

int main(void)
{
    std::cout << "This is test for checking build-status" << std::endl;
    
    Buffer buffer(256, 256, 3);
    fillColor(&buffer, 30, 230, 180, 50, GRColor::Red);
    fillColor(&buffer, 100, 190, 250, 100, GRColor::White);
    buffer.writeBMPFile("../Data/Textures/Box/rendered_image.bmp");
    
    return 0;
}