#include <iostream>
#include <memory>

#include "../header/camera.hpp"
#include "../header/color.hpp"
#include "../header/hitRecord.hpp"
#include "../header/hittable_arr.hpp"
#include "../header/hittable.hpp"
#include "../header/interval.hpp"
#include "../header/ray.hpp"
#include "../header/sphere.hpp"
#include "../header/vec3d.hpp"

#define PIXEL_HEIGHT 1080
#define PIXEL_WIDTH 1920
#define SAMPLES_PER_PIXEL 20

int main(void)
{
    Camera cam = Camera(PIXEL_WIDTH , PIXEL_HEIGHT);

    HittableArray sceneObjects = HittableArray();

    Sphere sphereObj = Sphere(Vec3D(0.0f , 0 , 0.0f) , 1.5f);
    Sphere sphereBase = Sphere(Vec3D(0.0f , 0.0f , -6.5f) , 5.0f);

    sceneObjects.objArray.push_back(&sphereObj);
    sceneObjects.objArray.push_back(&sphereBase);

    std::cout << "P3\n";
    std::cout << PIXEL_WIDTH << ' ' << PIXEL_HEIGHT << '\n';
    std::cout << 255 << '\n'; 

    for (int i = 0 ; i<PIXEL_HEIGHT ; i++)
    {
        for (int j =0 ; j<PIXEL_WIDTH ; j++)
        {
            Color pixelColor = Color(0 , 0 , 0);
            for (int s=0 ; s<SAMPLES_PER_PIXEL ; s++)
            {
                Ray shotRay = cam.ShootSampleRay(j , i);
                Color sampleColor = sceneObjects.SceneInteract(shotRay , Interval(0.1f , 100.0f));
                pixelColor = pixelColor + sampleColor;
            }
            (pixelColor / SAMPLES_PER_PIXEL).WriteColor();
        }
    }
}