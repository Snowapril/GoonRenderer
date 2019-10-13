#pragma once

namespace gr
{
    struct GRColor
    {
        unsigned char color[4];
        
        GRColor(unsigned char _r, unsigned char _g, unsigned char _b) noexcept;
        GRColor(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a) noexcept;
        unsigned char& operator[](int _index);
        unsigned char const& operator[](int _index) const;
        
        const static GRColor Red;
		const static GRColor Green;
		const static GRColor Blue;
		const static GRColor Black;
		const static GRColor White;
    };
    
    struct BufferInfo 
    {
        int width;
        int height;
        int numChannels;
        int bitCount;
    };
    
    struct Pixel
    {
        GRColor color;
        int x, y;
        
        Pixel(int _x, int _y, GRColor _color) noexcept;
    };
    
    using GoonID = unsigned int;
};
