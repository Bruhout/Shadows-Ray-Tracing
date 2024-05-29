#include "../include/interval.hpp"
#include <random>

Interval::Interval()
    : min(-1000000),
      max(1000000)
{/*Defaults to between -ve one million and +ve one million*/

}

Interval::Interval(float Min , float Max)
    : min(Min),
      max(Max)
{}

float Interval::GetSize()
{
    return max - min;
}

bool Interval::Contains(float Value)
{
    if (Value > max)
        return false;
    else if (Value < min)
        return false;
    else
        return true;
}

float Interval::RandNum()
{
    return dis(gen);
}
