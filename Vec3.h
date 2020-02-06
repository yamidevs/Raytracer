//
// Created by yamisaaf on 06/02/2020.
//

#include <iostream>
#include <fstream>

#ifndef RAYTRACER_VECTOR_H
#define RAYTRACER_VECTOR_H

#include "cmath"

namespace Raytracer{

    template<typename  T>
    class Vec3 {
    private:

    public:
        T x,y,z;
        Vec3() : x(0),y(0),z(0) {}
        ~Vec3(){}
        Vec3(const T & _x,const T &_y,const T & _z) : x(_x),y(_y),z(_z){}

        T operator*(const Vec3 & vec) const{
            return x * vec.x + y*vec.y + z * vec.z;
        }

        Vec3 operator*(const T &value ) const{
            return Vec3(x * value , y * value , z*value);
        }

        Vec3 operator+(const Vec3 & vec) const{
            return Vec3(x + vec.x , y+ vec.y,z + vec.z);
        }

        Vec3 operator-(const Vec3 & vec) const{
            return Vec3(x - vec.x , y - vec.y , z - vec.z);
        }

        Vec3 getNormalize() const{
            Vec3 result(x,y,z);
            result.normalize();
            return result;
        }

        T norm(){
            return x * x   + y  *y+ z*z;
        }

        Vec3& normalize(){
            float n = norm();
            if (n > 0) {
                float factor = 1 / sqrt(n);
                x *= factor, y *= factor, z *= factor;
            }
            return *this;
        }
    };
}


typedef Raytracer::Vec3<float> Vec3f;




#endif //RAYTRACER_VECTOR_H
