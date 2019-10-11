#include "DataType.h"

namespace gr
{
	const GRColor GRColor::Red		= GRColor(255, 0, 0, 255);
	const GRColor GRColor::Green	= GRColor(0, 255, 0, 255);
	const GRColor GRColor::Blue		= GRColor(0, 0, 255, 255);
	const GRColor GRColor::Black	= GRColor(0, 0, 0, 255);
	const GRColor GRColor::White	= GRColor(255, 255, 255, 255);

	GRColor::GRColor(unsigned char _r, unsigned char _g, unsigned char _b) noexcept
        : color { _r, _g, _b, 255 } 
    {
    };
    GRColor::GRColor(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a) noexcept
        : color { _r, _g, _b, _a }
    {       
    };
    unsigned char& GRColor::operator[](int _index)
    {
        return color[_index];
    }
    unsigned char const& GRColor::operator[](int _index) const
    {
        return color[_index];
    }
    
    Pixel::Pixel(int _x, int _y, GRColor _color) noexcept
            : x(_x), y(_y), color(_color) {};
};