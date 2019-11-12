#include <iostream>
#include "Window.h"
#include "MeshRenderer.h"
#include "LineRenderer.h"
#include "Buffer.h"
#include <gbmp/bmp_image.h>
#include "ObjReader.h"
#include <algorithm>
using namespace gr;

int main(void)
{
    std::cout << "This is test for checking build-status" << std::endl;
    
    ObjReader reader;
    if (!reader.readObjFile("../Data/Model/low_poly_sphere.obj")) std::cerr << "Failed to read obj File" << std::endl;
    
    Window window(1024, 1024, 3, "SW Rendering");
    
    Buffer* defaultBuffer = window.getDefaultBuffer();
    
    std::vector<gm::vec3> const &pos_stack = reader.pos_stack;
    std::vector<gm::uvec3> const &pos_idx_stack = reader.pos_idx_stack;
    
    std::cout << "#Vertices : " << pos_stack.size() << std::endl;
    std::cout << "#Indices : " << pos_idx_stack.size() << std::endl;
    for (auto const& indices : pos_idx_stack)
    {
        gm::ivec2 vertices[] = {
            gm::ivec2(pos_stack[indices.x].x, pos_stack[indices.x].y) * 1024.0f,
            gm::ivec2(pos_stack[indices.y].x, pos_stack[indices.y].y) * 1024.0f,
            gm::ivec2(pos_stack[indices.z].x, pos_stack[indices.z].y) * 1024.0f
        };
        
        gm::vec3 colors[] = {
            gm::vec3(1.0f, 0.0f, 0.0f),
            gm::vec3(0.0f, 1.0f, 0.0f),
            gm::vec3(0.0f, 0.0f, 1.0f)
        };
        
        triangle(vertices, defaultBuffer, colors);
        //drawLine(gm::ivec2(int(v0.x), int(v0.y)), gm::ivec2(int(v1.x), int(v1.y)), defaultBuffer, gm::vec3(1.0f, 1.0f, 1.0f));
        //drawLine(gm::ivec2(int(v1.x), int(v1.y)), gm::ivec2(int(v2.x), int(v2.y)), defaultBuffer, gm::vec3(1.0f, 1.0f, 1.0f));
        //drawLine(gm::ivec2(int(v2.x), int(v2.y)), gm::ivec2(int(v0.x), int(v0.y)), defaultBuffer, gm::vec3(1.0f, 1.0f, 1.0f));
    }
    
    unsigned char* data = defaultBuffer->data();
    BufferInfo bufferInfo = defaultBuffer->getBufferInfo();
    unsigned char* temp = gbmp::gbmp_bgr_to_rgb(data, bufferInfo.width, bufferInfo.height, bufferInfo.numChannels);
    gbmp::gbmp_write_image("../Data/Textures/Box/rendered_image.bmp", temp, bufferInfo.width, bufferInfo.height, bufferInfo.numChannels);
    gbmp::gbmp_free_image(temp);
    
    int a[] = {3, 1, 5, 10};
    std::sort(std::begin(a), std::end(a), [](int x1, int x2) {
        return x1 > x2;
    });
    
    for (auto i : a) std::cout << i << std::endl;
    
    return 0;
}