#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include "Image.h"
#include "Scene.h"
#include "Sphere.h"
#include "Camera.h"
using  namespace std;


int main() {
    Raytracer::Scene scene(Raytracer::Camera(Vec3f(0,0,0)));
    scene.addObject(new Raytracer::Sphere(Vec3f(0,0,-55),10));
    Raytracer::Image render(1000,1000);
    scene.start(render);
    render.Save("./file1.ppm");
    return 0;
}
