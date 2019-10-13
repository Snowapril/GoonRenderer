#include "Object/VBO.h"

namespace gr
{
    VBO::VBO(void* _vertices, std::vector< VertexStrideInfo >&& _verticesInfo) noexcept
        : vertices(_vertices), verticesInfo(std::move(_verticesInfo))
    {
        
    }
    VBO::~VBO() noexcept
    {
        if (vertices != nullptr)
            delete vertices;
    }
};