#include "../include/vec3d.hpp"
#include "../include/ray.hpp"
#include "../include/sphere.hpp"
#include "../include/interval.hpp"
#include "../include/hitRecord.hpp"


Sphere::Sphere()
    : center{0 , 0 , 0},
      radius(1.0f)
{
}

Sphere::Sphere(Vec3D Center , float Radius)
    : center(Center),
      radius(Radius)
{
}

bool Sphere::HitCheck(Ray shotRay , Interval tInterval , HitRecord* hitRec)
{
    float b = 2 * shotRay.B.DotProduct(shotRay.A - center);
    float a = shotRay.B.MagnitudeSq();
    float c = (shotRay.A.MagnitudeSq() + center.MagnitudeSq() - (shotRay.A.DotProduct(center) * 2) - (radius * radius));

    if ((b*b - 4*a*c) > 0)
    {
        float tValue = (-b - pow(b*b - 4*a*c , 0.5)) / (2 * a);
        if (tInterval.Contains(tValue))
        {
            hitRec->tHit = tValue;
            hitRec->hitPoint = shotRay.PointFromT(tValue);
            hitRec->surfaceNormal = GetNormal(shotRay.PointFromT(tValue));
            hitRec->hitObjPtr = this;
        }

        return true;
    }
        
    else
    {
        hitRec->tHit = -100000.0f;
        hitRec->hitPoint = Vec3D();
        hitRec->surfaceNormal = Vec3D();
        hitRec->hitObjPtr = NULL;

        return false;
    }
}

float Sphere::HitCheckT(Ray shotRay, Interval tInterval)
{
    float b = 2 * shotRay.B.DotProduct(shotRay.A - center);
    float a = shotRay.B.MagnitudeSq();
    float c = (shotRay.A.MagnitudeSq() + center.MagnitudeSq() - (shotRay.A.DotProduct(center) * 2) - (radius * radius));

    if ((b*b - 4*a*c) > 0)
    {
        float tValue = (-b - pow(b*b - 4*a*c , 0.5)) / 2 * a;
        return tValue;
    }
        
    else
    {
        return -100000.0f;
    }
}


Vec3D Sphere::GetNormal(Vec3D hitPoint) 
{
    Vec3D normalVec = (center - hitPoint) / (center - hitPoint).Magnitude();
    return normalVec;
}

void Sphere::PrintSphere()
{
    std::clog << "Center:";
    center.PrintVec();
    std::clog << "Radius" << radius << "\n";
}

