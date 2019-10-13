#pragma once

#include "HeaderPrerequistes.h"
#include "gm/vec3.h"

namespace gr
{
    void setColor(gm::vec3 _v, Buffer* _buffer, gm::vec3 _color) noexcept;
    void drawLine(gm::vec3 _v1, gm::vec3 _v2, Buffer* _buffer, gm::vec3 _color) noexcept;
};