//
// Created by yamisaaf on 06/02/2020.
//

#ifndef RAYTRACER_SHAPE_H
#define RAYTRACER_SHAPE_H

#include "Ray.h"
#include "Vec3.h"
namespace Raytracer{
    class Shape {
    public:
        Shape(){}
        virtual ~Shape(){}
        virtual bool isRayIntersect(const Ray &rayon, Vec3f &p) = 0;
    };
}
#endif //RAYTRACER_SHAPE_H
