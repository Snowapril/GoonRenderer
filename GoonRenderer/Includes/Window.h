#pragma once

#include "SwapChain.h"

#include <string>
#include <memory>

namespace gr
{
    /**
     * Represent Screen which is the target of the rendering.
     */
    class Window
    {
    private:
        SwapChain* swapchain;
        std::string title;
        int  width {0};
        int height {0};
    public:
        Window() = default;
        ~Window();

        void attachSwapChain(SwapChain* swapchain) noexcept;
        void setWindowSize(int width, int height) noexcept;
        void setWindowTitle(char const* title) noexcept;

        std::pair<int, int> getWindowSize() const noexcept;
        std::string getWindowTitle() const noexcept;
    };
};