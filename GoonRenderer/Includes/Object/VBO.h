#pragma once

#include "../DataType.h"

namespace gr
{
    class VBO
    {
    private:
        void* vertices = nullptr;
        std::vector< VertexStrideInfo > verticesInfo;
    public:
        VBO() = default;
        VBO(void* _vertices, std::vector< VertexStrideInfo >&& _verticesInfo) noexcept;
        ~VBO() noexcept;
    public:
        
    };
};