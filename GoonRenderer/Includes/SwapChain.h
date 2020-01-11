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
        using buffer_type  = Buffer*;
        using storage_type = std::vector<buffer_type>;

        SwapChain() = default;
        ~SwapChain();

        void addBuffer(Buffer* buffer) noexcept;
    private:
        storage_type buffers;
        int cur_index = 0;
    };
};