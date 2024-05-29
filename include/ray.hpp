#ifndef RAY_HPP
#define RAY_HPP
#include <iostream>
#include <math.h>
#include "vec3d.hpp"

class Ray
{
public:
    Vec3D A;
    Vec3D B;

    Ray(Vec3D a , Vec3D b);

    void PrintRay();

    Vec3D PointFromT(float t);

    static Ray GetRandomReflection(Vec3D incidentPoint , Vec3D surfaceNormal);

    Ray GetDirectReflecton(Vec3D incidentPoint , Vec3D surfaceNormal);

    Ray GetFuzzyReflecton(Vec3D incidentPoint , Vec3D surfaceNormal , float fuzz);
};


#endif // RAY_HPP