#include <iostream>
#include "Window.h"
#include "MeshRenderer.h"
#include "LineRenderer.h"
#include "Buffer.h"
#include <gbmp/bmp_image.h>
using namespace gr;

int main(void)
{
    std::cout << "This is test for checking build-status" << std::endl;
    
    Window window(256, 256, 3, "SW Rendering");
    
    Buffer* defaultBuffer = window.getDefaultBuffer();
    
    fillColor(gm::ivec2(30, 50), gm::ivec2(180, 230), defaultBuffer, gm::vec3(1.0f, 0.0f, 0.0f));
    fillColor(gm::ivec2(100, 100), gm::ivec2(250, 190), defaultBuffer, gm::vec3(1.0f, 1.0f, 1.0f));
    drawLine(gm::ivec2(30, 30), gm::ivec2(180, 200), defaultBuffer, gm::vec3(0.0f, 1.0f, 1.0f));
    drawLine(gm::ivec2(230, 30), gm::ivec2(180, 100), defaultBuffer, gm::vec3(0.0f, 1.0f, 1.0f));
    drawLine(gm::ivec2(180, 30), gm::ivec2(180, 100), defaultBuffer, gm::vec3(0.0f, 1.0f, 1.0f));
    drawLine(gm::ivec2(10, 200), gm::ivec2(250, 200), defaultBuffer, gm::vec3(0.3f, 0.9f, 0.3f));
    unsigned char* data = defaultBuffer->data();
    BufferInfo bufferInfo = defaultBuffer->getBufferInfo();
    unsigned char* temp = gbmp::gbmp_bgr_to_rgb(data, bufferInfo.width, bufferInfo.height, bufferInfo.numChannels);
    gbmp::gbmp_write_image("../Data/Textures/Box/rendered_image.bmp", temp, bufferInfo.width, bufferInfo.height, bufferInfo.numChannels);
    gbmp::gbmp_free_image(temp);
    
    return 0;
}