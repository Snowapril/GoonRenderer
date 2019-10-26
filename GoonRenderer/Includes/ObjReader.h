#pragma once

#include <gm/vec3.h>
#include <gm/vec2.h>
#include <vector>

namespace gr
{
    class ObjReader
    {
    public:
        std::vector<gm::vec3> pos_stack;
        std::vector<gm::vec3> normal_stack;
        std::vector<gm::vec2> uv_stack;
        std::vector<gm::uvec3> pos_idx_stack;
    public:
        ObjReader() = default;
        
        bool readObjFile(char const* path, bool _rescale_to_unit = true) noexcept;
        // min, max vectors represent left bottom and right top of bounding box(bb).
        void rescaleBoundingBox(gm::vec3 const& _min, gm::vec3 const& _max) noexcept;
    };
};