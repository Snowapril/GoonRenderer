#include "Window.h"
#include <gbmp/bmp_image.h>
#include "Context.h"
#include "Buffer.h"

namespace gr
{
    Window::Window(int _width, int _height, int _nunChannels, char const* _title) noexcept
        : title(_title), width(_width), height(_height)
    {
        this->context = std::make_shared<Context>();
        this->context->generateBuffer(this->width, this->height, _nunChannels, nullptr);
    }
    
    Window::Window(char const* _path_to_image, char const* _title) noexcept
        : title(_title)
    {
        this->context = std::make_shared<Context>();
        int numChannels;
        unsigned char* initialData = gbmp::gbmp_load_image(_path_to_image, &(this->width), &(this->height), &numChannels);
        this->context->generateBuffer(this->width, this->height, numChannels, initialData);
    }
    
    Window::~Window()
    {
        if (context) this->context.reset();
    }
        
    Buffer* Window::getDefaultBuffer() noexcept
    {
        return this->context->getBufferByIndex(0);
    }
    std::shared_ptr< Context > Window::getCurrentContext() noexcept
    {
        return this->context;    
    }
    void Window::setContextCurrent(std::shared_ptr< Context > _context) noexcept
    {
        this->context = _context;
    }
};