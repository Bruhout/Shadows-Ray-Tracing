#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "vec3d.hpp"
#include "ray.hpp"
#include "hittable.hpp"
#include "hitRecord.hpp"

class Sphere : public Hittable 
{
public:
    // Member variables
    Vec3D center;
    float radius;

    // Constructors
    Sphere();
    Sphere(Vec3D Center, float Radius);

    // Functions declared but not defined (prototypes)
    bool HitCheck(Ray shotRay, Interval tInterval, HitRecord* hitRec) override;
    float HitCheckT(Ray shotRay, Interval tInterval) override;
    Vec3D GetNormal(Vec3D hitPoint) override;
    void PrintSphere();
};

#endif // SPHERE_HPP
