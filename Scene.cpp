//
// Created by yamisaaf on 06/02/2020.
//

#include "Scene.h"
#include "Ray.h"
#include "Image.h"

void Raytracer::Scene::addObject(Raytracer::Shape  *shape){
    objects.push_back(shape);
}

void Raytracer::Scene::addLight(Raytracer::Light light){
    lights.push_back(light);
}

void Raytracer::Scene::start(Raytracer::Image & img) {
    for(int y = 0;y<img.height;y++){
        for(int x = 0;x<img.width;x++) {

            Raytracer::Ray ray(Vec3f(0,0,0),camera.WorldToCamera(Vec3f(x,y,-1),img));
            for(auto &i : objects){
                Vec3f usless;
                if(i->isRayIntersect(ray,usless)){
                    img.Update(y,x,RGB(255, 0, 0));
                }else{
                    img.Update(y,x,RGB(0, 0, 0));
                }
            }
        }
    }
}

Raytracer::Scene::~Scene(){
    for(auto &i : objects){
        delete i;
    }
}

