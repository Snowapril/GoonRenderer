// reference on https://en.wikipedia.org/wiki/BMP_file_format 

#include <fstream>

namespace gbmp
{
    #pragma pack(push, 2)
    struct bmp_file_header
    {                                       // offset
        unsigned short header_field;        //   0
        unsigned int   size_of_bmp_file;    //   2
        unsigned short reserved_1;          //   6
        unsigned short reserved_2;          //   8
        unsigned int   offset_pixel_start;  //   10
    };
    #pragma pack(pop)
    
    unsigned char* gbmp_load_image(char const* _image_path, unsigned int* _width, unsigned int* _height, unsigned int* _num_channels)
    {
        
    }
};