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

#include "HeaderPrerequistes.h"
#include "RenderingPipeline.h"
#include "Context.h"

namespace gr
{
    class Renderer
    {
    private:
        RenderingPipeline pipeline;
        Context* context;
        
        Package* pack;
    public:
        Renderer(char const* config_path=nullptr) noexcept;
        ~Renderer();

        void setupRenderer(char const* config_path = nullptr) noexcept;
        void attachWindow(Window* window) noexcept;
        void destroyRenderer() noexcept;

        void loadSceneObjects(SwapChain* chain, Scene* scene, View* view, Camera* cam) noexcept;
        void unloadSceneObjects() noexcept;
        //! Simulate the renderer for generating one frame.
        void simulate_image(char const* image_path="rendering.bmp") noexcept;
        //! Simulate the renderer with given FPS and Time for generating video.
        void simulate_video(float time_limit, float fps, char const* video_path="rendering.mp4") noexcept;
    };
};