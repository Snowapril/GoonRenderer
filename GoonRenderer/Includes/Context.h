#pragma once

#include <vector>
#include "DataType.h"
#include "HeaderPrerequistes.h"

namespace gr
{
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
        GoonID generateVBO(void *_data, std::vector< VertexStrideInfo >&& _vStrideInfos, GoonEnum _usage) noexcept;
        GoonID generateBuffer(int _width, int _height, int _numChannels, unsigned char *_data=nullptr);
        Buffer* getBufferByIndex(int _index) noexcept;
    public:
    };
};