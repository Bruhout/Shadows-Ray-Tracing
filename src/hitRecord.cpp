#include "../header/hitRecord.hpp"
#include "../header/vec3d.hpp"
#include "../header/hittable.hpp"

HitRecord::HitRecord()
    : tHit(-100000.0f),
      hitPoint{0 , 0 , 0},
      surfaceNormal(0 , 0 , 1),
      hitObjPtr(NULL)
{}

HitRecord::HitRecord(float THit , Vec3D HitPoint , Vec3D SurfaceNormal , Hittable* HitObjPtr)
    : tHit(THit),
      hitPoint(HitPoint),
      surfaceNormal(SurfaceNormal),
      hitObjPtr(HitObjPtr)
{}