#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <random>

static std::random_device rd;
static std::mt19937 gen;
static std::uniform_real_distribution<> dis(0.0f , 1.0f);

class Interval
{
public:
    float min;
    float max;

    Interval();

    Interval(float Min , float Max);

    float GetSize();

    bool Contains(float Value);

    float RandNum();
};

#endif // INTERVAL_HPP
