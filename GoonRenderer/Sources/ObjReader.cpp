#include "ObjReader.h"
#include <fstream>
#include <cstring>
#include <sstream>
#include <iostream>

#define MIN(v1, v2) ((v1) > (v2) ? (v2) : (v1))
#define MAX(v1, v2) ((v1) > (v2) ? (v1) : (v2))

namespace gr
{
    bool ObjReader::readObjFile(char const* path, bool _rescale_to_unit) noexcept
    {
        std::ifstream objFile;
        objFile.open(path);
        
        if (objFile.is_open())
        {
            gm::vec3 min, max;
            char buffer[255];
            while (objFile >> buffer)
            {
                if (strcmp(buffer, "v") == 0) // vertices
                {
                    float x, y, z;
                    objFile >> x >> y >> z;
                    pos_stack.push_back(gm::vec3(x, y, z));
                    
                    if (_rescale_to_unit)
                    {
                        min.x = MIN(min.x, x);
                        min.y = MIN(min.y, y);
                        min.z = MIN(min.z, z);
                        
                        max.x = MAX(max.x, x);
                        max.y = MAX(max.y, y);
                        max.z = MAX(max.z, z);
                    }
                }
                else if (strcmp(buffer, "f") == 0)
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
            objFile.clear();
            objFile.close();
            
            if (_rescale_to_unit)
            {
                rescaleBoundingBox(min, max);
            }
        }
        else 
        {
            return -1;
        }
        
        return 0;
    }
    
    void ObjReader::rescaleBoundingBox(gm::vec3 const& _min, gm::vec3 const& _max) noexcept
    {
        gm::vec3 const& scale = _max - _min;
        float max_v = MAX(scale.x, MAX(scale.y, scale.z));
        float inv_max_v = 1.0f / max_v;
        std::cout << "min : " << _min.x << ", " << _min.y << ", " << _min.z << std::endl;
        std::cout << "max : " << _max.x << ", " << _max.y << ", " << _max.z << std::endl;
        for (auto& pos : pos_stack) 
            pos = (pos - _min) *  inv_max_v;
    }
}
