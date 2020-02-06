//
// Created by yamisaaf on 06/02/2020.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include "Image.h"
#include "Shape.h"
#include "Light.h"
#include "Camera.h"
namespace Raytracer{
    class Scene {
    public:
        Scene(const Camera&  _c) : camera(_c){}
        ~Scene();

        void addObject(Raytracer::Shape *  shape);
        void addLight(Raytracer::Light light);
        void start(Raytracer::Image&  img);


    private:
        std::vector<Raytracer::Shape * > objects;
        std::vector<Raytracer::Light> lights;
        Raytracer::Camera camera;
    };
}



#endif //RAYTRACER_SCENE_H
