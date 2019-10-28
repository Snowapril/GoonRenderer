#pragma once

#include <gm/vec3.h>
#include <gm/vec2.h>
#include <vector>

namespace gr
{
    /*
    * Obj Parser class which also provide the several useful method, such as, rescaling bounding box.
    * Unless destruct objreader instance, user can use the vertices data continuously.
    */
    class ObjReader
    {
    public:
        std::vector<gm::vec3> pos_stack;
        std::vector<gm::vec3> normal_stack;
        std::vector<gm::vec2> uv_stack;
        std::vector<gm::uvec3> pos_idx_stack;
    public:
        ObjReader() = default;
        /*
        * Parsing Obj file with given path parameter. 
        * If _rescale_to_unit is true, scale the all positions in to the unit bounding box.
        */
        bool readObjFile(char const* path, bool _rescale_to_unit = true) noexcept;
    private:
        //! bbmin, bbmax vectors represent left bottom and right top of bounding box(bb).
        void rescaleBoundingBox(gm::vec3 const& _bbmin, gm::vec3 const& _bbmax) noexcept;
    };
};