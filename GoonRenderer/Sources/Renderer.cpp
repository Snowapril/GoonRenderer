#include "Renderer.h"

namespace gr
{
    Renderer::Renderer(char const* config_path) noexcept
    {
        setupRenderer(config_path);
    }
    //! Keep deallocate order (because context class manages whole resources.)
    Renderer::~Renderer()
    {
        destroyRenderer();
    }
    
    void Renderer::setupRenderer(char const* config_path) noexcept
    {
        if (config_path)
        {

        }
        else
        {
            context = new Context();
            pipeline.setupPipeline();
        }
    }

    void Renderer::destroyRenderer() noexcept
    {
        if (context)
        {
            delete context; context = nullptr;
        }
    }

    void Renderer::loadSceneObjects(SwapChain* chain, Scene* scene, View* view, Camera* cam) noexcept
    {
        
    }
    void Renderer::unloadSceneObjects() noexcept
    {
        
    }

    void Renderer::simulate_image(char const* image_path) noexcept
    {

    }
    
    void Renderer::simulate_video(float time_limit, float fps, char const* video_path) noexcept
    {

    }
    
};