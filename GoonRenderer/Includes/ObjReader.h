#pragma once

#include <gm/vector.h>
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
        * @param _path is absolute or relative path of the obj file
        * @param if _rescale_to_unit is true, rescaling to unit bounding box will be done after reading obj file.
        */
        bool readObjFile(char const* _path, bool _rescale_to_unit = true) noexcept;
    private:
        /*
        * Rescale model to unit scale. Scaling and Translating will be done for fitting in the unit box.
        * @param _bbmin mean left bottom vertex of the bounding box before scaling.
        * @param _bbmax mean right top vertex of the bounding box before scaling.
        */
        void rescaleBoundingBox(gm::vec3 const& _bbmin, gm::vec3 const& _bbmax) noexcept;
    };
};