#pragma once

/*
* https://medium.com/@bgolus/anti-aliased-alpha-test-the-esoteric-alpha-to-coverage-8b177335ae4f
* Alpha-to-Coverage(A2C) technique and use of MSAA for VR
* 요즘 게임들은 Deferred rendering같은 technique으로 인해서, 또는 MSAA의 high-cost로 인해 FXAA를 사용함.
* 근데 VR환경에서는 MSAA 가 괜찮음.
*/

#include "HeaderPrerequistes.h"

#include <vector>
#include <memory>

namespace gr
{
    /*
    * Main pipeline of this GoonRenderer. 
    * Each modularized stage will generate visibly correct rendering result.
    * Each stage get the essential resources from the current context.
    */
    class RenderingPipeline
    {
    private:
        std::shared_ptr< Context > context;
        std::unique_ptr< InputAssembler > assember;
        std::unique_ptr<   Rasterizer   > rasterizer;
        std::vector< std::unique_ptr< VertexShader > > vertexShaders;
        std::vector< std::unique_ptr<FragmentShader> > fragmentShaders;
    public:
        //! Return current context which whole stages of rendering pipeline are utilizing.
        std::shared_ptr< Context > getCurrentContext() noexcept;
        //! Set the context of rendering pipeline with given parameter.
        void setContextCurrent(std::shared_ptr< Context > _context) noexcept;
    public:
        /*
        * Simulate the rendering pipeline with given FPS and Time.
        * If _video_path is not equal to nullptr, 
        * this method will generate the video which is simulating result of the rendering pipeline.
        */
        void simulate(float _time_limit, float _fps, char const* _video_path=nullptr) noexcept;
    };
};