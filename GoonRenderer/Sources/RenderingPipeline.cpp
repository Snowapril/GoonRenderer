#include "RenderingPipeline.h"
// https://medium.com/@bgolus/anti-aliased-alpha-test-the-esoteric-alpha-to-coverage-8b177335ae4f
// Alpha-to-Coverage(A2C) technique and use of MSAA for VR
// 요즘 게임들은 Deferred rendering같은 technique으로 인해서, 또는 MSAA의 high-cost로 인해 FXAA를 사용함.
// 근데 VR환경에서는 MSAA 가 괜찮음.

namespace gr
{
    std::shared_ptr< Context > RenderingPipeline::getCurrentContext() noexcept
    {
        return this->context;
    }
    
    void RenderingPipeline::setContextCurrent(std::shared_ptr< Context > _context) noexcept
    {
        this->context = _context;
    }
    
    void RenderingPipeline::simulate(float _time_limit, float _fps, char const* _video_path) noexcept
    {
        
    }
};
