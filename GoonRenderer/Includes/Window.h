#pragma once

#include "HeaderPrerequistes.h"
#include <memory>

namespace gr
{
    class Window
    {
    private:
        std::shared_ptr< Context > context;
        std::string title;
        int  width {0};
        int height {0};
    public:
        Window() = delete;
        // Intialize the buffer with bmp image data.
        Window(int _width, int _height, int _nunChannels, char const* _title) noexcept;
        Window(char const* _path_to_image, char const* _title) noexcept;
        ~Window();
    public:
        Buffer* getDefaultBuffer() noexcept;
        std::shared_ptr< Context > getCurrentContext() noexcept;
        void setContextCurrent(std::shared_ptr< Context > _context) noexcept;
    };
};