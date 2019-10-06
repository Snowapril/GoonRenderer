#pragma once

#include "Colorbuffer.h"

namespace gr
{
    class Texture : public Colorbuffer
    {
    protected:
    public:
        Texture() = default;
        
        void bindTexture() const noexcept;
        void unbindTexture() const noexcept;
    };
};