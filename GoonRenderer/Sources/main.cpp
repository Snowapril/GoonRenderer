#include <iostream>
#include <algorithm>
#include <gbmp/bmp_image.h>

#include "Window.h"
#include "MeshRenderer.h"
#include "LineRenderer.h"
#include "Buffer.h"
#include "ObjReader.h"

#include <gm/vectorial.h>
using namespace gr;

int main(void)
{
    std::cout << "This is test for checking build-status" << std::endl;
    
    ObjReader reader;
    if (!reader.readObjFile("../Data/Model/bunny.obj")) std::cerr << "Failed to read obj File" << std::endl;
    
    Window window(1024, 1024, 3, "SW Rendering");
    
    Buffer* defaultBuffer = window.getDefaultBuffer();
    
    std::vector<gm::vec3> const &pos_stack = reader.pos_stack;
    std::vector<gm::uvec3> const &pos_idx_stack = reader.pos_idx_stack;
    
    std::cout << "#Vertices : " << pos_stack.size() << std::endl;
    std::cout << "#Indices : " << pos_idx_stack.size() << std::endl;

    for (auto const& indices : pos_idx_stack)
    {
        gm::ivec2 vertices[] = {
            gm::vec2(pos_stack[indices.x].x, pos_stack[indices.x].y) * 1024.0f,
            gm::vec2(pos_stack[indices.y].x, pos_stack[indices.y].y) * 1024.0f,
            gm::vec2(pos_stack[indices.z].x, pos_stack[indices.z].y) * 1024.0f
        };
        
        float randomValue1 = rand() / static_cast<float>(RAND_MAX + 1);
        float randomValue2 = rand() / static_cast<float>(RAND_MAX + 1);
        float randomValue3 = rand() / static_cast<float>(RAND_MAX + 1);
        gm::vec3 colors[] = {
            gm::vec3(randomValue1,randomValue2,randomValue3),
            gm::vec3(randomValue1,randomValue2,randomValue3),
            gm::vec3(randomValue1,randomValue2,randomValue3)
        };
        
        triangle(vertices, defaultBuffer, colors);
        //drawLine(vertices[0], vertices[1], defaultBuffer, colors[0]);
        //drawLine(vertices[1], vertices[2], defaultBuffer, colors[1]);
        //drawLine(vertices[2], vertices[0], defaultBuffer, colors[2]);
    }
    
    unsigned char* data = defaultBuffer->data();
    BufferInfo bufferInfo = defaultBuffer->getBufferInfo();
    unsigned char* temp = gbmp::gbmp_bgr_to_rgb(data, bufferInfo.width, bufferInfo.height, bufferInfo.numChannels);
    gbmp::gbmp_write_image("../Data/Textures/Box/rendered_image.bmp", temp, bufferInfo.width, bufferInfo.height, bufferInfo.numChannels);
    gbmp::gbmp_free_image(temp);
    
    return 0;
}