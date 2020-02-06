//
// Created by yamisaaf on 06/02/2020.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Shape.h"
#include "Vec3.h"
namespace Raytracer{
    class Sphere : public Raytracer::Shape{
    private:
        Vec3f center;
        float radius;
    public:
        Sphere(Vec3f _c , float _r) :center(_c) , radius(_r) {}
        virtual ~Sphere(){}
        bool isRayIntersect(const Ray& rayon, Vec3f &p);
    };

}


#endif //RAYTRACER_SPHERE_H
