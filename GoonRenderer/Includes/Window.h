#pragma once

#include "HeaderPrerequistes.h"
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
        std::shared_ptr< Context > context;
        std::string title;
        int  width {0};
        int height {0};
    public:
        Window() = delete;
        //! Construct window with uninitialized framebuffer.
        Window(int _width, int _height, int _nunChannels, char const* _title) noexcept;
        //! Construct window with bmp image data.
        Window(char const* _path_to_image, char const* _title) noexcept;
        ~Window();
    public:
        //! return the default buffer of the current context.
        Buffer* getDefaultBuffer() noexcept;
        //! return the current context.
        std::shared_ptr< Context > getCurrentContext() noexcept;
        //! set the current context with given argument.
        void setContextCurrent(std::shared_ptr< Context > _context) noexcept;
    };
};