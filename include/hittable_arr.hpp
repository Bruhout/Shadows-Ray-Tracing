#ifndef HITTABLE_ARR_HPP
#define HITTABLE_ARR_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "hittable.hpp"
#include "interval.hpp"
#include "hitRecord.hpp"
#include "color.hpp"

// Very important : The coloring of the ray and the reflection of the ray is handled completely separately
// Material class handles how the ray is reflected with RayInteract() function
// Color class handles how the ray is colored with the attentuation() function

class HittableArray
{
public:
    std::vector<Hittable*> objArray;

    HittableArray();

    // Check if the hitObjPtr is NULL and faceMaterialPtr is NULL.
    // tHit is -100000.0f for no hit
    // Just return info about the ray hit if any takes place
    bool HitCheckArray(Ray shotRay , Interval tInterval , HitRecord* hitRec);

    // take in one ray, calculate intersection and spawn another from that point till maxDepth
    Color SceneInteract(Ray shotRay , Interval tInterval);
};

#endif // HITTABLE_ARR_HPP