#pragma once

#include "../Buffer.h"

namespace gr
{
    class Texture : public Buffer
    {
    public:
        Texture() = default;
        
        void bindTexture() const noexcept;
        void unbindTexture() const noexcept;
    };
};