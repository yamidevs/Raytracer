//
// Created by yamisaaf on 06/02/2020.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H


#include "Vec3.h"
#include "Image.h"

namespace Raytracer{
    class Camera {
    private:
        Vec3f origin;
        float fov;
    public:
        Camera(const Vec3f& _o) : origin(_o){
            fov = 60 * M_PI  /180;
        }

        ~Camera(){}
        Vec3f WorldToCamera(const Vec3f &pos ,const Raytracer::Image&) const;
    };
}


#endif //RAYTRACER_CAMERA_H
