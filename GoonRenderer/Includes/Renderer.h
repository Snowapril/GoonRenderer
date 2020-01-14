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
    public:
        Renderer(char const* config_path) noexcept;
        ~Renderer();
        //! Bans copy and move constructor and assignment operator.
        Renderer(Renderer const&) = delete;
        Renderer& operator=(Renderer const&) = delete;
        Renderer& operator=(Renderer&&) = delete;
        Renderer(Renderer&&) = delete;

        struct Package
        {
            SwapChain* swapchain { nullptr };
            Scene* scene { nullptr };
            View* view { nullptr };
            Camera* cam { nullptr };
        };
    public:
        void setupRenderer(char const* config_path = nullptr) noexcept;
        void destroyRenderer() noexcept;

        /**
         * @brief prepare package in advance, load them to renderer.
         * @param package - package will be rendered.
         */
        void loadPackage(Package package) noexcept;
        /**
         * @brief return package pointer for swapping it's part.
         */
        Package getPackage() noexcept;
        /**
         * @brief return package pointer for swapping it's part.
         * @param newPackage - package which has part for replacing original part.
         * \code{.cpp}
	     * Package pack = renderer.getPackage();
         * pack.scene = newScene;
         * renderer.replacePackage(pack);
	     * \endcode
         */
        void replacePackage(Package newPackage) noexcept;

        //! Simulate the renderer for generating one frame.
        void simulate_image(char const* image_path="rendering.bmp") noexcept;
        //! Simulate the renderer with given FPS and Time for generating video.
        void simulate_video(float time_limit, float fps, char const* video_path="rendering.mp4") noexcept;
    private:
        RenderingPipeline pipeline;
        Context* context = nullptr;
        Package pack;  
    };
};