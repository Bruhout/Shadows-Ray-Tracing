#ifndef COLOR_HPP
#define COLOR_HPP
#include <iostream>

class Color
{
public:
    int R;
    int G;
    int B;

    Color();

    Color(int r , int g , int b);

    Color operator*(float factor);

    Color operator+(Color col2);

    Color operator/(int samples);

    void WriteColor();

    void PrintColor();


    Color Attenuate(Color subtractedColor);
};

#endif // COLOR_HPP
