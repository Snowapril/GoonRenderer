#pragma once

#include "HeaderPrerequistes.h"
#include "gm/vec2.h"
#include "gm/vec3.h"

namespace gr
{
    //! fill color in the bounding box that given _bbmin, _bbmax parameters represent.
    void rectangle(gm::ivec2 _bbmin, gm::ivec2 _bbmax, Buffer *_buffer, gm::vec3 _color) noexcept;
    
    //! rasterize triangle with given three vertices.
    void triangle(gm::ivec2 _v0, gm::ivec2 _v1, gm::ivec2 _v2, Buffer *_buffer, gm::vec3 _color) noexcept;
};