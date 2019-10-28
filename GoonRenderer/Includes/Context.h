#pragma once

#include <vector>
#include "DataType.h"
#include "HeaderPrerequistes.h"

namespace gr
{
    /*
    *   This class manages whole resources which are generated during on simulating rendering pipeline.
    */
    class Context
    {
    private:
        std::vector< Buffer* > buffers;
        std::vector< VBO* > staticVBOs;
        std::vector< VBO* > dynamicVBOs;
    public:
        Context() = default;
        ~Context() noexcept;
    public:
        //! Generate  Vertex Buffer Object with given parameters and return ID value of the object.
        GoonID generateVBO(void *_data, std::vector< VertexStrideInfo >&& _vStrideInfos, GoonEnum _usage) noexcept;
        //! Generate  Buffer Object with given parameters and return ID value of the object.
        GoonID generateBuffer(int _width, int _height, int _numChannels, unsigned char *_data=nullptr);
        //! Return pointer of the buffer object with given id value.
        Buffer* getBufferByIndex(int _id) noexcept;
    public:
    };
};