#include <iostream>
#include "Window.h"
#include "MeshRenderer.h"
#include "LineRenderer.h"
#include "Buffer.h"
#include <gbmp/bmp_image.h>
#include "ObjReader.h"
using namespace gr;

int main(void)
{
    std::cout << "This is test for checking build-status" << std::endl;
    
    ObjReader reader;
    if (reader.readObjFile("../Data/Model/man_head.obj")) std::cerr << "Failed to read obj File" << std::endl;
    
    Window window(1024, 1024, 3, "SW Rendering");
    
    Buffer* defaultBuffer = window.getDefaultBuffer();
    
    std::vector<gm::vec3> const &pos_stack = reader.pos_stack;
    std::vector<gm::uvec3> const &pos_idx_stack = reader.pos_idx_stack;
    
    std::cout << "#Vertices : " << pos_stack.size() << std::endl;
    std::cout << "#Indices : " << pos_idx_stack.size() << std::endl;
    for (auto const& indices : pos_idx_stack)
    {
        auto v0 = pos_stack[indices.x];
        auto v1 = pos_stack[indices.y];
        auto v2 = pos_stack[indices.z];
        
        std::cout << "v0 : " << v0.x << ", " << v0.y << ", " << v0.z << std::endl;
        std::cout << "v1 : " << v1.x << ", " << v1.y << ", " << v1.z << std::endl;
        std::cout << "v2 : " << v2.x << ", " << v2.y << ", " << v2.z << std::endl;
        std::cout << std::endl;
        
        v0 = v0 * 1024.0f + gm::vec3(128, 0, 0);
        v1 = v1 * 1024.0f + gm::vec3(128, 0, 0);
        v2 = v2 * 1024.0f + gm::vec3(128, 0, 0);
        
        drawLine(gm::ivec2(int(v0.x), int(v0.y)), gm::ivec2(int(v1.x), int(v1.y)), defaultBuffer, gm::vec3(1.0f, 1.0f, 1.0f));
        drawLine(gm::ivec2(int(v1.x), int(v1.y)), gm::ivec2(int(v2.x), int(v2.y)), defaultBuffer, gm::vec3(1.0f, 1.0f, 1.0f));
        drawLine(gm::ivec2(int(v2.x), int(v2.y)), gm::ivec2(int(v0.x), int(v0.y)), defaultBuffer, gm::vec3(1.0f, 1.0f, 1.0f));
    }
    
    unsigned char* data = defaultBuffer->data();
    BufferInfo bufferInfo = defaultBuffer->getBufferInfo();
    unsigned char* temp = gbmp::gbmp_bgr_to_rgb(data, bufferInfo.width, bufferInfo.height, bufferInfo.numChannels);
    gbmp::gbmp_write_image("../Data/Textures/Box/rendered_image.bmp", temp, bufferInfo.width, bufferInfo.height, bufferInfo.numChannels);
    gbmp::gbmp_free_image(temp);
    
    return 0;
}