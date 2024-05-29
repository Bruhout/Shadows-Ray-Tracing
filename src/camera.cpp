#include "../header/camera.hpp"
#include "../header/vec3d.hpp"
#include "../header/ray.hpp"
#include "../header/interval.hpp"

Camera::Camera()
    : camPos{0 , 6 , 0},
      frameOrigin{1 , 4 , 1},
      xVec{-2 , 0 , 0},
      yVec{0 , 0 , -2},
      xRes(256),
      yRes(256)
{}

Camera::Camera(Vec3D CamPos , Vec3D FrameOrigin , Vec3D XVec , Vec3D YVec , int XRes , int YRes)
    : camPos(CamPos),
      frameOrigin(FrameOrigin),
      xVec(XVec),
      yVec(YVec),
      xRes(XRes),
      yRes(YRes)
{}

Camera::Camera(int XRes , int YRes)
    : camPos{0 , 6 , 0},
      frameOrigin{1.0f * ((float)XRes/(float)YRes), 4 , 1.0f},
      xVec{-2 * ((float)XRes/(float)YRes) , 0 , 0},
      yVec{0 , 0 , -2},
      xRes(XRes),
      yRes(YRes)
{}
/*
the default camera has a length of 2 units by 2 units and resolution of 256 x 256 pixels
Each pixel is a window into the world though which rays can be shot
one way is to make the camera frame get bigger as you add more pixels. but this means that to have a large fov you need a high resolution. not good.
another way is to make the camera frame fixed in size (2 x 2 here). and the size of the pixels changes. 
for higher resolutions, each pixel is smaller. this is the approach used by me.
so for the most part the camera frame will remain fixed (with respect to the camera)

the frame's shape changes only when Xres/Yres changes. if the imagine is made longer horizontally, the camera frame moves a bit to the left.
this ensures that the camera itself is always pointed right in the middle of the frame.
*/

Ray Camera::ShootRay(int xCoord , int yCoord)
{
    Vec3D xVecDx = xVec / xRes;
    Vec3D yVecDy = yVec / yRes;

    Vec3D rayDirection = (frameOrigin + (xVecDx * xCoord) + (yVecDy * yCoord)) - camPos;
    rayDirection = rayDirection / rayDirection.Magnitude();
    Ray shotRay = Ray(camPos , rayDirection);
    return shotRay;
}


Ray Camera::ShootSampleRay(int xCoord , int yCoord)
{
    Vec3D xVecDx = xVec / xRes;
    Vec3D yVecDy = yVec / yRes;

    float xOffset = Interval(0.0f , 1.0f).RandNum();
    float yOffset = Interval(0.0f , 1.0f).RandNum();

    Vec3D rayDirection = (frameOrigin + (xVecDx * (xCoord + xOffset)) + (yVecDy * (yCoord + yOffset))) - camPos;
    rayDirection = rayDirection / rayDirection.Magnitude();
    Ray shotRay = Ray(camPos , rayDirection);
    return shotRay;
}