#include <iostream>
#include "Window.h"
#include "MeshRenderer.h"
#include "LineRenderer.h"
#include <gbmp/bmp_image.h>
using namespace gr;

int main(void)
{
    std::cout << "This is test for checking build-status" << std::endl;
    
    Window window(256, 256, 3, "SW Rendering");
    
    Buffer* defaultBuffer = window.getDefaultBuffer();
    
    fillColor(gm::ivec2(30, 50), gm::ivec2(180, 230), defaultBuffer, gm::vec3(1.0f, 0.0f, 0.0f));
    fillColor(gm::ivec2(100, 100), gm::ivec2(250, 190), defaultBuffer, gm::vec3(1.0f, 1.0f, 1.0f));
    
    unsigned char* data = defaultBuffer->data();
    BufferInfo bufferInfo = defaultBuffer->getBufferInfo();
    
    unsigned char* temp = gbmp::gbmp_bgr_to_rgb(data, bufferInfo.width, bufferInfo.height, bufferInfo.numChannels);
    gbmp::gbmp_write_image("../Data/Textures/Box/rendered_image.bmp", temp, bufferInfo.width, bufferInfo.height, bufferInfo.numChannels);
    gbmp::gbmp_free_image(temp);
    
    return 0;
}