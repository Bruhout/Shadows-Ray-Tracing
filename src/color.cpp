#include "../header/color.hpp"
#include <iostream>

Color::Color()
    : R(255),
      G(255),
      B(255)
{}

Color::Color(int r , int g , int b)
    : R(r),
      G(g),
      B(b)
{}

Color Color::operator*(float factor)
{
    return Color((int)(factor*R) , (int)(factor*G) , (int)(factor*B));
}

Color Color::operator+(Color col2)
{
    return Color(R+col2.R , G+col2.G , B+col2.B);
}

Color Color::operator/(int samples)
{
    return Color(R/samples , G/samples , B/samples);
}

// void Color::WriteColor()
// {
//     std::cout << (int)(R%256) << ' ' << (int)(G%256) << ' ' << (int)(B%256) << '\n';
// }

void Color::WriteColor()
{
    std::cout << (int)(R) << ' ' << (int)(G) << ' ' << (int)(B) << '\n';
}
void Color::PrintColor()
{
    std::clog << "Color: " << '[' << R << ',' << G << ',' << B << "]\n";
}



Color Color::Attenuate(Color subtractedColor)
{
    int newRed = R - subtractedColor.R;
    int newGreen = G - subtractedColor.G;
    int newBlue = B - subtractedColor.B;

    if (newRed < 0)
    {
        newRed = 0;
    }

    if (newGreen < 0)
    {
        newGreen = 0;
    }        
    
    if (newBlue < 0)
    {
        newBlue = 0;
    }
    
    return Color(newRed , newGreen , newBlue);
}