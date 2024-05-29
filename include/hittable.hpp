#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include <iostream>
#include "ray.hpp"
#include "interval.hpp"

class HitRecord;

class Hittable
{
public:
    virtual ~Hittable() = default;

    virtual bool HitCheck(Ray shotRay , Interval tInterval , HitRecord* hitRec) = 0;

    virtual float HitCheckT(Ray shotRay , Interval) = 0;

    virtual Vec3D GetNormal(Vec3D hitPoint) = 0;
};

#endif // HITTABLE_HPP