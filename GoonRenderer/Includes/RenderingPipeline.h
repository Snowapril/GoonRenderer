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
        std::unique_ptr< InputAssembler > assember;
        std::unique_ptr<   Rasterizer   > rasterizer;

    public:
        RenderingPipeline() = default;
        ~RenderingPipeline();
    };
};