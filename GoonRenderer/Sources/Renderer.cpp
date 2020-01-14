#include "Renderer.h"

#include "SwapChain.h"
#include "Scene.h"
#include "View.h"
#include "Camera.h"

#include <utility>

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
        context = new Context();
        if (config_path)
        {

        }
        else
        {
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

    void Renderer::loadPackage(Renderer::Package package) noexcept
    {
        this->pack = package;
    }

    Renderer::Package Renderer::getPackage() noexcept
    {
        return this->pack;
    }

    void Renderer::replacePackage(Package newPackage) noexcept
    {
        using std::swap;
        if (pack.swapchain != newPackage.swapchain)
        {
            delete pack.swapchain;
            pack.swapchain = newPackage.swapchain;
        }

        if (pack.scene != newPackage.scene)
        {
            delete pack.scene;
            pack.scene = newPackage.scene;
        }

        if (pack.view != newPackage.view)
        {
            delete pack.view;
            pack.view = newPackage.view;
        }

        if (pack.cam != newPackage.cam)
        {
            delete pack.cam;
            pack.cam = newPackage.cam;
        }
    }

    void Renderer::simulate_image(char const* image_path) noexcept
    {

    }
    
    void Renderer::simulate_video(float time_limit, float fps, char const* video_path) noexcept
    {

    }
    
};