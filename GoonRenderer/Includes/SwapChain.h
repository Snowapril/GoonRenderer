/*
 * @file SwapChain.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief 
 * @date 2020-01-11
 * 
 * @copyright Copyright (c) 2019 snowapril
 * This code is licensed under MIT License (see LICENSE for details)
 * 
 */
#pragma once

#include "Buffer.h"

#include <vector>

namespace gr
{
    class SwapChain
    {
    public:
        using buffer_ptr = Buffer*;
        using buffer_const_ptr = Buffer const*;
        using storage_type = std::vector<buffer_ptr>;

        SwapChain() = default;
        ~SwapChain() noexcept;

        //! add buffer to swap chain. 
        //! the number of the buffer can be 1, 2 and 3. (single buffer, double-buffering, tri-buffering)
        void addBuffer(Buffer* buffer) noexcept;
        //! front buffer in needed only for copying to video RAM
        buffer_const_ptr getFrontBuffer() const noexcept; 
        //! back buffer is used for drawing.
        buffer_ptr getBackBuffer() noexcept;
        //! update every render frame for swapping front and back buffers.
        void swap() noexcept;
        //! allocate memory to buffers (load all buffers).
        void initBuffers();
    private:
        storage_type buffers;
        int front_index = 0, back_index = 0;
    };
};