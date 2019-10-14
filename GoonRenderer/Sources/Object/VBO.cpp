#include "Object/VBO.h"

namespace gr
{
    VBO::VBO(void* _vertices, std::vector< VertexStrideInfo >&& _verticesInfos)
        : vertices(_vertices), verticesInfos(std::move(_verticesInfos))
    {
    }
    VBO::~VBO()
    {
        if (vertices)
        {
            unsigned char* temp = reinterpret_cast<unsigned char*>(vertices);
            delete[] temp;
            vertices = nullptr;
        }
    }
};