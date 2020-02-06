//
// Created by yamisaaf on 06/02/2020.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vec3.h"
namespace Raytracer{
    class Ray {
    public:
        Ray(const Vec3f& _o,const Vec3f& _d) : origin(_o) , dir(_d){}
        Vec3f origin , dir;
    };
}



#endif //RAYTRACER_RAY_H
