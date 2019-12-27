#include "ObjReader.h"
#include "Util.h"

#include <fstream>
#include <cstring>
#include <sstream>
#include <iostream>
#include <limits>

namespace gr
{
    bool ObjReader::readObjFile(char const* _path, bool _rescale_to_unit) noexcept
    {
        std::ifstream objFile;
        objFile.open(_path);
        
        if (objFile.is_open())
        {
            gm::vec3 bbMin(std::numeric_limits<float>::max()), bbMax(std::numeric_limits<float>::min());
            char buffer[255];
            while (objFile >> buffer)
            {
                if (strcmp(buffer, "v") == 0) //! vertices
                {
                    float x, y, z;
                    objFile >> x >> y >> z;
                    pos_stack.push_back(gm::vec3(x, y, z));
                    
                    if (_rescale_to_unit)
                    {
                        bbMin.x = gr::min(bbMin.x, x);
                        bbMin.y = gr::min(bbMin.y, y);
                        bbMin.z = gr::min(bbMin.z, z);
                        
                        bbMax.x = gr::max(bbMax.x, x);
                        bbMax.y = gr::max(bbMax.y, y);
                        bbMax.z = gr::max(bbMax.z, z);
                    }
                }
                else if (strcmp(buffer, "f") == 0) //! Faces
                {
                    unsigned int vt[3], nt[3], ut[3];
                    char temp;
                    
                    for (int i = 0; i < 3; i++)
                    {
                        objFile >> buffer;
                        std::stringstream sstr(buffer);    
                        
                        sstr >> vt[i]; sstr >> temp;
                        sstr >> nt[i]; sstr >> temp;
                        sstr >> ut[i];
                        
                        vt[i]--;
                        nt[i]--;
                        ut[i]--;
                    }
                    
                    pos_idx_stack.push_back(gm::uvec3(vt[0], vt[1], vt[2]));
                }
            }
            objFile.clear(); objFile.close();
            
            if (_rescale_to_unit)
            {
                std::cout << "min : " << bbMin.x << ", " << bbMin.y << ", " << bbMin.z << std::endl;
                std::cout << "max : " << bbMax.x << ", " << bbMax.y << ", " << bbMax.z << std::endl;
                rescaleBoundingBox(bbMin, bbMax);
            }
        }
        else //! If reading the file with given path was failed.
        {
            return false;
        }
        
        return true;
    }
    
    void ObjReader::rescaleBoundingBox(gm::vec3 const& _bbmin, gm::vec3 const& _bbmax) noexcept
    {
        gm::vec3 const& scale = _bbmax - _bbmin;
        float max_v = gr::max(scale.x, gr::max(scale.y, scale.z));
        float inv_max_v = 1.0f / max_v;
        
        for (auto& pos : pos_stack) 
            pos = (pos - _bbmin) *  inv_max_v;
    }
}
