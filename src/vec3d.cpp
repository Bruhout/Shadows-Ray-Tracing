#include "../include/vec3d.hpp"
#include "../include/interval.hpp"
#include <math.h>
#include <iostream>

Vec3D::Vec3D()
    : x(0),
      y(0),
      z(0) 
{}

Vec3D::Vec3D(float X , float Y , float Z)
    : x(X),
      y(Y),
      z(Z) 
{}

Vec3D Vec3D::operator-(Vec3D vec2)
{
    Vec3D subVec = {
        x - vec2.x,
        y - vec2.y,
        z - vec2.z
    };

    return subVec;
}

Vec3D Vec3D::operator+(Vec3D vec2)
{
    Vec3D subVec = {
        x + vec2.x,
        y + vec2.y,
        z + vec2.z
    };

    return subVec;
}

Vec3D Vec3D::operator*(float scalar)
{
    Vec3D subVec = {
        x * scalar,
        y * scalar,
        z * scalar
    };

    return subVec;
}

Vec3D Vec3D::operator/(float scalar)
{
    Vec3D subVec = {
        x / scalar,
        y / scalar,
        z / scalar
    };

    return subVec;
}


float Vec3D::MagnitudeSq()
{
    return pow(x, 2) + pow(y , 2) + pow(z, 2);
}

float Vec3D::Magnitude()
{
    return pow(MagnitudeSq() , 0.5);
}

float Vec3D::DistanceFrom(Vec3D refPoint)
{
    return ((refPoint - *this).Magnitude());
}

Vec3D Vec3D::CrossProduct(Vec3D vec2)
{
    Vec3D productVec = {
        ((y * vec2.z) - (z * vec2.y)),
        -((x * vec2.z) - (z * vec2.x)),
        ((x * vec2.y) - (y * vec2.x))
    };
    return productVec;
}

float Vec3D::DotProduct(Vec3D vec2)
{
    return (x * vec2.x) + (y * vec2.y) + (z * vec2.z);
}

Vec3D Vec3D::GetUnitVec()
{
    Vec3D origin = {0,0,0};
    float mag = DistanceFrom(origin);
    Vec3D unitVec = {
        x / mag,
        y / mag,
        z / mag
    };

    return unitVec;
}

Vec3D Vec3D::ProjectOnto(Vec3D ontoVec)
{
    float scaleFactor = DotProduct(ontoVec) / ontoVec.Magnitude();

    Vec3D projVec = ontoVec.GetUnitVec() * scaleFactor;

    return projVec;
}

void Vec3D::PrintVec()
{
    std::clog << "(" << x << ',' << y << ',' << z << ")\n";
}

bool Vec3D::Equality(Vec3D vec2)
{
    if (x == vec2.x && y == vec2.y && z == vec2.z)
    {
        return true;
    }
    return false;
}


Vec3D Vec3D::GetRandDir()
{
    Interval randInterval = Interval(-1.0f , 1.0f);
    Vec3D randVec = Vec3D(
        randInterval.RandNum(),
        randInterval.RandNum(),
        randInterval.RandNum()
    );
    randVec = randVec / randVec.Magnitude();

    return randVec;
}


Vec3D Vec3D::GetDirectReflection(Vec3D surfaceNormal)
{
    Vec3D incidenceProjected = ProjectOnto(surfaceNormal);
    Vec3D reflectedRayDirection = (incidenceProjected * -2.0f) + (*this);
    reflectedRayDirection = reflectedRayDirection / reflectedRayDirection.Magnitude(); 

    return reflectedRayDirection;
}

Vec3D Vec3D::VectorInUnitSector(float theta , float phi)
{
    Vec3D differenceVec = *this - Vec3D(0 , 0 , 1);
    Vec3D newXVec = (Vec3D(1 , 0 , 0) + differenceVec).GetUnitVec();
    Vec3D newYVec = (Vec3D(0 , 1 , 0) + differenceVec).GetUnitVec();
    Vec3D newZVec = (Vec3D(0 , 0 , 1) + differenceVec).GetUnitVec();

    return (
        newXVec * (sin(theta) * cos(phi)) + 
        newYVec * (sin(theta) * sin(phi)) +  
        newZVec * cos(theta)
    ).GetUnitVec();
}
