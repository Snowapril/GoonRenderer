#include <iostream>
#include <algorithm>
#include <gbmp/bmp_image.h>

#include "MeshRenderer.h"
#include "LineRenderer.h"
#include "Buffer.h"
#include "ObjReader.h"
#include "SwapChain.h"
#include "Context.h"
#include "Renderer.h"

#include <gm/vectorial.h>
using namespace gr;

int main(void)
{
    Renderer renderer;
    
    auto& context = Context::getMutableInstance();
    SwapChain* chain = new SwapChain;
    chain->addBuffer( context.generateResource<Buffer>(1024, 1024, 3) );
    chain->addBuffer( context.generateResource<Buffer>(1024, 1024, 3) );
    chain->addBuffer( context.generateResource<Buffer>(1024, 1024, 3) );

    
    Buffer* backbuffer = chain->getBackBuffer();
    ObjReader reader;
    if (!reader.readObjFile("../Data/Model/bunny.obj")) std::cerr << "Failed to read obj File" << std::endl;
    
    std::vector<gm::vec3 > const &pos_stack = reader.pos_stack;
    std::vector<gm::uvec3> const &pos_idx_stack = reader.pos_idx_stack;
    
    std::cout << "#Vertices : " << pos_stack.size()     << std::endl;
    std::cout << "#Indices : "  << pos_idx_stack.size() << std::endl;

    for (auto const& indices : pos_idx_stack)
    {
        gm::ivec2 vertices[] = {
            gm::vec2(pos_stack[indices.x].x, pos_stack[indices.x].y) * 1024.0f,
            gm::vec2(pos_stack[indices.y].x, pos_stack[indices.y].y) * 1024.0f,
            gm::vec2(pos_stack[indices.z].x, pos_stack[indices.z].y) * 1024.0f
        };
        
        float randomValue1 = rand() / static_cast<float>(RAND_MAX + 1LL);
        float randomValue2 = rand() / static_cast<float>(RAND_MAX + 1LL);
        float randomValue3 = rand() / static_cast<float>(RAND_MAX + 1LL);
        gm::vec3 colors[] = {
            gm::vec3(randomValue1,randomValue2,randomValue3),
            gm::vec3(randomValue1,randomValue2,randomValue3),
            gm::vec3(randomValue1,randomValue2,randomValue3)
        };
        
        triangle(vertices, backbuffer, colors);
        //drawLine(vertices[0], vertices[1], defaultBuffer, colors[0]);
        //drawLine(vertices[1], vertices[2], defaultBuffer, colors[1]);
        //drawLine(vertices[2], vertices[0], defaultBuffer, colors[2]);
    }
    chain->swap();
    Buffer const* frontBuffer = chain->getFrontBuffer();
    unsigned char const* data = frontBuffer->data();
    BufferInfo bufferInfo = frontBuffer->getBufferInfo();

    int width = bufferInfo.width;
    int height = bufferInfo.height;
    int numChannels = bufferInfo.numChannels;

    unsigned char* temp = gbmp::gbmp_bgr_to_rgb(data, width, height, numChannels);
    gbmp::gbmp_write_image("image.bmp", temp, width, height, numChannels);
    gbmp::gbmp_free_image(temp);
    
    return 0;
}