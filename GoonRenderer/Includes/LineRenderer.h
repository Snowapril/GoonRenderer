#pragma once

#include "HeaderPrerequistes.h"
#include <gm/vector.h>

namespace gr
{
    //! Set color on the pixel with given position.
    void setColor(gm::ivec2 _v, Buffer* _buffer, gm::vec3 _color) noexcept;
  
    //! Draw line between two given vertices.
    void drawLine(gm::ivec2 _v1, gm::ivec2 _v2, Buffer* _buffer, gm::vec3 _color) noexcept;
};