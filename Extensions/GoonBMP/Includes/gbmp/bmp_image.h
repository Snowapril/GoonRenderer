// reference on https://en.wikipedia.org/wiki/BMP_file_format 
#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <cstring>

namespace gbmp
{
    using uint8_t  = unsigned char;
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
        uint32_t header_size                {  0 };
        int32_t width                       {  0 };
        int32_t height                      {  0 };
        uint16_t num_color_planes           {  1 };
        uint16_t color_depth                {  0 };
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
    
    uint8_t* gbmp_load_image(char const* _image_path, int32_t* _width, int32_t* _height, int32_t* _num_channels, bool _isSRGB = false) noexcept
    {
        std::ifstream bmp { _image_path, std::ios_base::binary };
        bmp_file_header file_header;
        bmp_bitmap_header bitmap_header;
        bmp_color_table color_table;
        uint8_t* data = nullptr;
        
        if (bmp.is_open() == false)
        {
             std::cerr << "Cannot find file with path [ " << _image_path << " ]" << std::endl;
             return nullptr;
        }
        
        bmp.read(reinterpret_cast<char*>(&file_header), sizeof(file_header));
        if (file_header.header_field != 0x4D42)
        {
            std::cerr << "Invalid BMP file format" << std::endl;
            return nullptr;
        }
        
        bmp.read(reinterpret_cast<char*>(&bitmap_header), sizeof(bitmap_header));
        *_width = bitmap_header.width;
        *_height = bitmap_header.height;
        *_num_channels = static_cast<int32_t>(bitmap_header.color_depth * 0.125f);
        std::cout << "\tWidth : " << bitmap_header.width << ", Height : " << bitmap_header.height << std::endl;
        std::cout << "\tDepth : " << bitmap_header.color_depth << std::endl;
        if (bitmap_header.height < 0)
        {
            std::cerr << "This program only treat bmp image file which have it's origin at the left bottom corner" << std::endl;
            return nullptr;
        }
        
        std::size_t bit_count = static_cast<std::size_t>(bitmap_header.color_depth * 0.125f);
        std::size_t num_alloc = bitmap_header.width * bitmap_header.height * bit_count;
        data = new uint8_t[num_alloc];
        
        if (bitmap_header.width % 4 == 0)
        {
            bmp.read(reinterpret_cast<char*>(data), num_alloc);
        }
        else // bmp image file with extra zero-padding.
        {
            int32_t num_elements_row = bitmap_header.width * bit_count;
            int32_t padding_width = 4 - (num_elements_row % 4);
            uint8_t padding_data[4];
            
            for (int i = 0; i < bitmap_header.height; i++)
            {
                bmp.read(reinterpret_cast<char*>(data + num_elements_row * i), sizeof(char) * num_elements_row);
                bmp.read(reinterpret_cast<char*>(padding_data),                sizeof(char) * padding_width   );
            }
        }
        
        if (_isSRGB) // TODO : this work take a long time because of floating-point pow calculation. 
        {
            float invVal = 1.0f / 255.0f;
            for (std::size_t i = 0; i < num_alloc; i++) 
            {
                float fVal = static_cast<float>(data[i]) * invVal;
                float gammaCorrected = std::pow(fVal, 0.45f);
                data[i] = static_cast<uint8_t>(gammaCorrected * 255.0f);
            }
        }
        
        bmp.close();
        return data;
    }
    
    bool gbmp_write_image(std::string const& _path, uint8_t* _data, int32_t _width, int32_t _height, int32_t _num_channels) noexcept
    {
        if (_width <= 0 || _height <= 0) return false;
        
        std::ofstream bmp { _path, std::ios_base::binary };
        if (!bmp) return false;
        
        bmp_file_header     file_header;
        bmp_bitmap_header   bitmap_header;
        bmp_color_table     color_table;
        
        bool bTransparent = (_num_channels == 4);
        bitmap_header.width  = _width;
        bitmap_header.height = _height;
        
        if (bTransparent)
        {
            bitmap_header.header_size       = sizeof(bmp_bitmap_header) + sizeof(bmp_color_table);
            file_header.offset_pixel_start  = sizeof(bmp_file_header)   + sizeof(bmp_bitmap_header) + sizeof(bmp_color_table); 
            
            bitmap_header.color_depth = 32;
            bitmap_header.compression_method = 3;
            file_header.file_size = file_header.offset_pixel_start + _width * _height * _num_channels;
        }
        else
        {
            bitmap_header.header_size       = sizeof(bmp_bitmap_header);
            file_header.offset_pixel_start  = sizeof(bmp_file_header) + sizeof(bmp_bitmap_header);
            
            bitmap_header.color_depth = _num_channels * 8;
            bitmap_header.compression_method = 0;
            
            int32_t num_elements_row = _width * _num_channels;
            int32_t padding_width = 4 - (num_elements_row % 4);
            file_header.file_size = file_header.offset_pixel_start + _width * _height * _num_channels + _height * padding_width;
        }
        
        // write headers
        bmp.write(reinterpret_cast<const char*>(&file_header), sizeof(file_header));
        bmp.write(reinterpret_cast<const char*>(&bitmap_header), sizeof(bitmap_header));
        if (bTransparent) bmp.write(reinterpret_cast<const char*>(&color_table), sizeof(color_table));
        
        // write data 
        if (_width % 4 == 0)
        {
            bmp.write(reinterpret_cast<const char*>(_data), _width * _height * _num_channels);
        }
        else // need extra padding
        {
            int32_t num_elements_row = _width * _num_channels;
            int32_t padding_width = 4 - (num_elements_row % 4);
            unsigned char padding_data[4] = {0, };
            
            for (int i = 0; i < _height; ++i)
            {
                bmp.write(reinterpret_cast<const char*>(_data + num_elements_row * i), sizeof(char) * num_elements_row);
                bmp.write(reinterpret_cast<const char*>(padding_data), sizeof(char) * padding_width);
            }
        }
        bmp.close();
        return true;
    }
    
    void gbmp_free_image(uint8_t* _data) noexcept
    {
        if (_data != nullptr)
            delete _data; // As unsigned char is primitive type, no need to use delete[].
    }
    
    // Very inefficient code. for only testing.
    // TODO : Refactoring this code.
    uint8_t* gbmp_bgr_to_rgb(uint8_t* _data, int32_t _width, int32_t _height, int32_t _numChannels) noexcept
    {
        std::size_t num_alloc = _width * _height * _numChannels;
        uint8_t *result = new uint8_t[num_alloc];
        
        std::memcpy(static_cast<void*>(result), static_cast<void*>(_data), num_alloc);
        
        uint8_t *temp_ptr = result;
        int iterCount = _width * _height;
        
        while (iterCount--)
        {
            uint8_t temp = *temp_ptr;
            *temp_ptr = *(temp_ptr + 2);
            *(temp_ptr + 2) = temp;
            temp_ptr += _numChannels;
        }
        
        return result;
    }
};