#include "SwapChain.h"
#include "Context.h"
#include <iostream>

namespace gr
{
    SwapChain::~SwapChain() noexcept
    {
        auto& context = Context::getMutableInstance();

        for (Buffer* buffer : this->buffers)
        {
            buffer->unload();
            context.destroyResource(buffer);
        }
    }

    void SwapChain::addBuffer(Buffer* buffer) noexcept
    {
        //! For compatibility with single-buffering.
        if (back_index == 0) back_index = 1;

        this->buffers.push_back(buffer);
    }
    
    SwapChain::buffer_const_ptr SwapChain::getFrontBuffer() const noexcept
    {
        return buffers[front_index];
    }
    
    SwapChain::buffer_ptr SwapChain::getBackBuffer() noexcept
    {
        return buffers[back_index];
    }

    void SwapChain::initBuffers()
    {
        try
        {
            for (Buffer* buffer : this->buffers)
                buffer->load();
        }
        catch( std::bad_alloc e )
        {
            std::cerr << e.what() << std::endl;
        }
    }

    void SwapChain::swap() noexcept
    {
        front_index = back_index;
        back_index = back_index + 1 == buffers.size() ? 0 : back_index + 1;
    }
};