#include <iostream>
#include "Buffer.h"
#include "MeshRenderer.h"
#include "LineRenderer.h"

using namespace gr;

int main(void)
{
    std::cout << "This is test for checking build-status" << std::endl;
    
    
    Buffer buffer(256, 256, 3);
    fillColor(gm::ivec2(30, 50), gm::ivec2(180, 230), &buffer, gm::vec3(1.0f, 0.0f, 0.0f));
    fillColor(gm::ivec2(100, 100), gm::ivec2(250, 190), &buffer, gm::vec3(1.0f, 1.0f, 1.0f));
    buffer.writeBMPFile("../Data/Textures/Box/rendered_image.bmp");
    
    return 0;
}