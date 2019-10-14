#pragma once

#include "HeaderPrerequistes.h"
#include "gm/vec2.h"
#include "gm/vec3.h"

namespace gr
{
    void setColor(gm::vec2 _v, Buffer* _buffer, gm::vec3 _color) noexcept;
    void drawLine(gm::vec2 _v1, gm::vec2 _v2, Buffer* _buffer, gm::vec3 _color) noexcept;
};