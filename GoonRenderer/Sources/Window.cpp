#include "Window.h"
#include <gbmp/bmp_image.h>
#include "Context.h"
#include "Buffer.h"

namespace gr
{    
    Window::~Window()
    {
        if (this->swapchain) delete this->swapchain;
    }
        
    void Window::attachSwapChain(SwapChain* swapchain) noexcept
    {
        this->swapchain = swapchain;
    }
    void Window::setWindowSize(int width, int height) noexcept
    {
        this->width  = width;
        this->height = height;
    }
    void Window::setWindowTitle(char const* title) noexcept
    {
        this->title = title;
    }
    std::pair<int, int> Window::getWindowSize() const noexcept
    {
        return std::make_pair(this->width, this->height);
    }
    std::string Window::getWindowTitle() const noexcept
    {
        return this->title;
    }
};