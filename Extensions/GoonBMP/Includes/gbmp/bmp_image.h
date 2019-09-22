// reference on https://en.wikipedia.org/wiki/BMP_file_format 

#include <fstream>
#include <optional>
#include <iostream>

namespace gbmp
{
    using uint16_t = unsigned short;
    using uint32_t = unsigned int;
    using int32_t  = int;
    
    #pragma pack(push, 1)
    struct bmp_file_header
    {                                
        uint16_t header_field       { 0x4D42 };   
        uint32_t file_size          {    0   };   
        uint16_t reserved_1         {    0   };         
        uint16_t reserved_2         {    0   };         
        uint32_t offset_pixel_start {    0   }; 
    }; // size : 14
    
    struct bmp_bitmap_header
    {
        uint32_t header_size                { 40 };
        int32_t width                       {  0 };
        int32_t height                      {  0 };
        uint16_t num_color_planes           {  1 };
        uint16_t color_depth                {  1 };
        uint32_t compression_method         {  0 };
        uint32_t image_size                 {  0 };
        int32_t horizontal_res              {  0 };
        int32_t vertical_res                {  0 };
        uint32_t number_of_colors           {  0 };
        uint32_t number_of_important_colors {  0 };
    };  // size : 40
    
    struct bmp_color_table 
    {
        uint32_t red_mask           { 0x00ff0000 };  // Bit mask for the red channel
        uint32_t green_mask         { 0x0000ff00 };  // Bit mask for the green channel
        uint32_t blue_mask          { 0x000000ff };  // Bit mask for the blue channel
        uint32_t alpha_mask         { 0xff000000 };  // Bit mask for the alpha channel
        uint32_t color_space_type   { 0x73524742 };  // Default "sRGB" (0x73524742)
        uint32_t unused[16]         {      0     };           // Unused data for sRGB color space    
    }; // size : 84
    #pragma pack(pop)
    
    std::optional<unsigned char*> gbmp_load_image(char const* _image_path, int* _width, int* _height, unsigned int* _num_channels)
    {
        std::ifstream bmp { _image_path, std::ios_base::binary };
        bmp_file_header file_header;
        bmp_bitmap_header bitmap_header;
        bmp_color_table color_table;
        unsigned char* data = nullptr;
        
        if (bmp.is_open() == false)
        {
             std::cerr << "Cannot find file with path [ " << _image_path << " ]" << std::endl;
             return {};
        }
        
        bmp.read(static_cast<char*>(&file_header), sizeof(file_header));
        if (file_header.header_field != 0x4D42)
        {
            std::cerr << "Invalid BMP file format" << std::endl;
            return {};
        }
        std::cout << "Image file path : " << _image_path << std::endl;
        std::cout << "\tFile size : " << file_header.file_size << std::endl;
        std::cout << "\tPixel offset : " << file_header.offset_pixel_start << std::endl;
        
        bmp.read(static_cast<char*>(&bitmap_header), sizeof(bitmap_header));
        std::cout << "\tWidth : " << bitmap_header.width << ", Height : " << bitmap_header.height << std::endl;
        std::cout << "\tDepth : " << bitmap_header.color_depth << std::endl;
        if (bitmap_header.height < 0)
        {
            std::cerr << "This program only treat bmp image file which have it's origin at the left bottom corner" << std::endl;
            return {};
        }
        
        if (bitmap_header.color_depth == 32) // if image have alpha channel
        {
            bitmap_header.header_size      = sizeof(bmp_bitmap_header) + sizeof(bmp_color_table);
            file_header.offset_pixel_start = sizeof(bmp_file_header)   + sizeof(bmp_bitmap_header) + sizeof(bmp_color_table);
        }
        else
        {
            bitmap_header.header_size        = sizeof(bmp_bitmap_header);
            file_header.offset_pixel_start = sizeof(bmp_file_header) + sizeof(bmp_bitmap_header);
        }
        file_header.file_size = file_header.offset_pixel_start;
        std::size_t num_alloc = bitmap_header.width * bitmap_header.height * static_cast<std::size_t>(bitmap_header.color_depth * 0.125f);
        data = new unsigned char[num_alloc];
        
        if (bitmap_header.width % 4 == 0)
        {
            bmp.read(static_cast<char*>(data), num_alloc);
            file_header.file_size += num_alloc;
        }
        else // bmp image file with extra zero-padding.
        {
            int32_t num_elements_row = bitmap_header.width * static_cast<int32_t>(bitmap_header.color_depth * 0.125f);
            int32_t padding_width = 4 - (bitmap_header.width % 4);
            unsigned char padding_data[4];
            
            for (int i = 0; i < bitmap_header.height; i++)
            {
                bmp.read(static_cast<char*>(data + num_elements_row * i), sizeof(char) * num_elements_row);
                bmp.read(static_cast<char*>(padding_data),                sizeof(char) * padding_width   );
            }
        }
        
        bmp.close();
        return { data };
    }
    
    void gbmp_free_image(unsigned char* _data) noexcept
    {
        if (_data != nullptr)
            delete _data; // As unsigned char is primitive type, no need to use delete[].
    }
};