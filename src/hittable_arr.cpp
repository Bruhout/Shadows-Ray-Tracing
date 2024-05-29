#include "../header/hittable_arr.hpp"
#include "../header/hittable.hpp"
#include "../header/vec3d.hpp"
#include "../header/hitRecord.hpp"
#include "../header/ray.hpp"
#include "../header/interval.hpp"
#include "../header/color.hpp"

HittableArray::HittableArray()
    : objArray{}
{}

// Check if the hitObjPtr is NULL and faceMaterialPtr is NULL.
// tHit is -100000.0f for no hit
// Just return info about the ray hit if any takes place
bool HittableArray::HitCheckArray(Ray shotRay , Interval tInterval , HitRecord* hitRec)
{
    float minT = tInterval.max;
    HitRecord minTRec = HitRecord();
    HitRecord tempRec = HitRecord();
    for (Hittable* obj : objArray)
    {
        if(obj->HitCheck(shotRay , tInterval , &tempRec) == true)
        {
            float currentTValue = tempRec.tHit;
            if (currentTValue < minT)
            {
                minT = currentTValue;
                minTRec = tempRec;
            }
        }
    }

    *hitRec = minTRec;
    
    if (minTRec.hitObjPtr == NULL)
    {
        return false;
    }
    return true;
}

// take in one ray, calculate intersection and spawn another from that point till maxDepth
Color HittableArray::SceneInteract(Ray shotRay , Interval tInterval)
{
    Vec3D lightSource = Vec3D(1000 , 1000 , 1000);
    HitRecord currentRayHitRecord = HitRecord();
    HitRecord lightRayHitRecord = HitRecord();
    if (!HitCheckArray(shotRay , tInterval , &currentRayHitRecord))
    {
        return Color(150 , 150 , 150);
    }

    else
    {
        Vec3D lightVec = (lightSource - currentRayHitRecord.hitPoint).GetUnitVec();
        if (HitCheckArray(Ray(currentRayHitRecord.hitPoint , lightVec) , Interval(0.001f , 100.0f) , &lightRayHitRecord))
        {
            return Color(0 , 0 , 0);
        }
        
        float dProd = lightVec.DotProduct(currentRayHitRecord.surfaceNormal);
        if (dProd <= 0)
        {
            return Color(200 , 100 , 255) * (dProd * -1);
        }
        return Color(0 , 0, 0);
    }
}