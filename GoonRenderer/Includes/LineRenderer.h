#pragma once

#include "HeaderPrerequistes.h"
#include "DataType.h"

namespace gr
{
    void setColor(Buffer* _buffer, Pixel _p) noexcept;
    void drawLine(Buffer* _buffer, Pixel _p1, Pixel _p2) noexcept;
};