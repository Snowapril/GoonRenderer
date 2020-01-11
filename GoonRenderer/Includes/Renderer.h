/*
 * @file Renderer.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief 
 * @date 2020-01-11
 * 
 * @copyright Copyright (c) 2019 snowapril
 * This code is licensed under MIT License (see LICENSE for details)
 * 
 */
#pragma once

#include "RenderingPipeline.h"
#include "Context.h"
#include "Window.h"

namespace gr
{
    class Renderer
    {
    private:
        RenderingPipeline pipeline;
        Context context;
        Window window;
    public:
        Renderer() = default;
        Renderer(char const* config_path=nullptr) noexcept;
        ~Renderer();
    public:
        //! Simulate the renderer for generating one frame.
        void simulate_image(char const* image_path="rendering.bmp") noexcept;
        //! Simulate the renderer with given FPS and Time for generating video.
        void simulate_video(float time_limit, float fps, char const* video_path="rendering.mp4") noexcept;
    };
};