//
// Created by yamisaaf on 06/02/2020.
//

#include "Sphere.h"

bool Raytracer::Sphere::isRayIntersect(const Ray &rayon, Vec3f& p){

    float a = 1;
    float b = 2 * (rayon.dir * (rayon.origin - center));
    float c = (rayon.origin -center ).norm() - radius * radius;

    float delta = b*b - 4 *a*c;
    if(delta <0) return false;
    double t1 =(-b - sqrtf(delta) / (2*a));
    double t2 =(-b + sqrtf(delta) / (2*a));
    if(t2 > 0) return true;

    return false;
}