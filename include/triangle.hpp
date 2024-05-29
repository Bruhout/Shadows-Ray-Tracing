#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include <iostream>
#include "vec3d.hpp"
#include "ray.hpp"
#include "color.hpp"
#include "hittable.hpp"

class Triangle : public Hittable
{
public:
    Vec3D verts[3];

    Triangle() : verts{{0,0,0} , {0,0,0} , {0,0,0}}
    {
        //pass
    }
    Triangle(Vec3D v1 , Vec3D v2 , Vec3D v3) : verts {v1 , v2 , v3}
    {
        //pass
    }

    void PrintTri()
    {
        for (int i = 0 ; i<3 ; i++)
        {
            verts[i].PrintVec();
        }
    }

    Vec3D GetNormal()
    {
        Vec3D vec1 = verts[1] - verts[0];
        Vec3D vec2 = verts[2] - verts[0];

        Vec3D crossProd = vec1.CrossProduct(vec2); 
        return crossProd / crossProd.Magnitude() ;
    }

    Vec3D RayPlaneIntersect(Ray shotRay)
    {
        Vec3D pointC = verts[0];
        Vec3D normalVec = GetNormal();
        Vec3D ACVec = pointC - shotRay.A;

        Vec3D ANVec = ACVec.ProjectOnto(normalVec);
        Vec3D AB_Vec = shotRay.B.ProjectOnto(normalVec);

        float APVecLen = ANVec.Magnitude() / AB_Vec.Magnitude();

        Vec3D pointP = shotRay.A + (shotRay.B * APVecLen);

        return pointP;
    }

    bool InTriangleCheck(Vec3D pointVec)
    {
        Vec3D side01 = verts[1] - verts[0];
        Vec3D side12 = verts[2] - verts[1];
        Vec3D side20 = verts[0] - verts[2];
    //-------

        Vec3D perp0 = ((side01.ProjectOnto(side12)) * -1) + verts[1];
        Vec3D perp0Line = perp0 - verts[0];

        Vec3D projectedPoint0 = (pointVec - verts[0]).ProjectOnto(perp0Line);

        float coord0 = projectedPoint0.Magnitude() / perp0Line.Magnitude();
    //-------------------------

        Vec3D perp1 = ((side12 * -1).ProjectOnto(side20)) + verts[2];
        Vec3D perp1Line = perp1 - verts[1];

        Vec3D projectedPoint1 = (pointVec - verts[1]).ProjectOnto(perp1Line);

        float coord1 = projectedPoint1.Magnitude() / perp1Line.Magnitude();
    //----------------------

        Vec3D perp2 = side12.ProjectOnto(side01) + verts[1];
        Vec3D perp2Line = perp2 - verts[2];

        Vec3D projectedPoint2 = (pointVec - verts[2]).ProjectOnto(perp2Line);

        float coord2 = projectedPoint2.Magnitude() / perp2Line.Magnitude();
        // std::clog << "perp0:";
        // perp0.PrintVec();
        // std::clog << "perp1:";
        // perp1.PrintVec();
        // std::clog << "perp2:";
        // perp2.PrintVec();
        // std::clog << coord0 << ',' << coord1 << ',' << coord2 << "\n";
    //-----------------------

        if (coord0 < 0 || coord1 < 0 || coord2 < 0 || coord0 > 1 || coord1 > 1 || coord2 > 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool HitCheck(Ray &shotRay , Interval tInterval)
    {
        Vec3D planeInterest = RayPlaneIntersect(shotRay);
        return InTriangleCheck(planeInterest);
    }

    Color GetColor(Vec3D lightSource)
    {
        Vec3D normalVec = GetNormal();
        float dProd = normalVec.DotProduct(verts[0] - lightSource);
        if (dProd < 0 || dProd == 0)
        {
            return Color(255 , 255 , 255) * (-1*dProd / lightSource.Magnitude());
        }
        else
        {
            return Color(0 , 0 , 0);
        }
    }
};

#endif // TRIANGLE_HPP