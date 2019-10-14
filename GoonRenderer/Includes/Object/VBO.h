#pragma once

#include <vector>
#include "../DataType.h"

namespace gr
{
    class VBO
    {
    private:
        void* vertices = nullptr;
        std::vector< VertexStrideInfo > verticesInfos;
    public:
        VBO() = default;
        VBO(void* _vertices, std::vector< VertexStrideInfo >&& _verticesInfos);
        ~VBO();
    public:
        
    };
};