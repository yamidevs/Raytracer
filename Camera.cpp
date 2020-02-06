//
// Created by yamisaaf on 06/02/2020.
//

#include "Camera.h"
#include "Vec3.h"
#include "Image.h"


Vec3f Raytracer::Camera::WorldToCamera(const Vec3f &pos ,const Raytracer::Image& image) const{

    float x = pos.x-(image.width/2);
    float y  = pos.y-(image.height/2);
    float z = -image.width / (2 * tan(fov /2));
    Vec3f direction(x, y, z);
    direction.normalize();
    return direction;

}

