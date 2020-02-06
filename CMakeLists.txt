cmake_minimum_required(VERSION 3.15)
project(raytracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(raytracer main.cpp Vec3.cpp Vec3.h Image.cpp Image.h Scene.cpp Scene.h Ray.cpp Ray.h Shape.cpp Shape.h Light.cpp Light.h Sphere.cpp Sphere.h Camera.cpp Camera.h)