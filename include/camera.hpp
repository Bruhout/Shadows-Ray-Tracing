#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "vec3d.hpp"
#include "ray.hpp"
#include "interval.hpp"

class Camera
{
public:
    Vec3D camPos;
    Vec3D frameOrigin;
    Vec3D xVec;
    Vec3D yVec;
    int xRes;
    int yRes;

    Camera();

    Camera(Vec3D CamPos , Vec3D FrameOrigin , Vec3D XVec , Vec3D YVec , int XRes , int YRes);

    Camera(int XRes , int YRes);

    Ray ShootRay(int xCoord , int yCoord);

    Ray ShootSampleRay(int xCoord , int yCoord);
};

#endif // CAMERA_HPP