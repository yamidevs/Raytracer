#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

using  namespace std;

// feature use template<> for float,int ...
class Vec3{
private:
    float x,y,z;
public:
    Vec3() : x(0),y(0),z(0) {}
    ~Vec3(){}
    Vec3(float _x,float _y,float _z) : x(_x),y(_y),z(_z){}

    float operator*(const Vec3 & vec) const{
        return x * vec.x + y *vec.y + z * vec.z;
    }

    Vec3 operator+(const Vec3 & vec) const{
        return Vec3(x+vec.x,y+vec.y,z+vec.z);
    }

    Vec3 operator-(const Vec3 & vec) const{
        return Vec3(x-vec.x,y-vec.y,z-vec.z);
    }

    float norm(){
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

    float clampX(){
        return (255 * max(0.f,min(1.f,x)));
    }

    float clampY(){
        return (255 * max(0.f,min(1.f,y)));
    }

    float clampZ(){
        return (255 * max(0.f,min(1.f,z)));
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec3& dt);

    friend Vec3 operator / (const float &r, const Vec3 &v);
};

std::ostream& operator<<(std::ostream & os , const Vec3 & v){
    os << v.x  << "  "  << v.y << "  " << v.z << " ";
    return os;
}


Vec3 operator / (const float &r, const Vec3 &v){
    return Vec3(r / v.x, r / v.y, r / v.z);
}

class Shape{
public:

    virtual bool isRayIntersect(const Vec3 & ray , const Vec3 & direction , float & t0) const = 0;
};
class Sphere : private Shape{
public:
    Vec3 center;
    float radius;
    Sphere(const Vec3 & c, const float & r) : center(c) , radius(r){}


    bool isRayIntersect(const Vec3 & ray , const Vec3 & direction , float & t0) const{
        Vec3 L = center - ray;
        float tca = L*direction;
        float d2 = L*L - tca*tca;
        if (d2 > radius*radius) return false;

        float thc = sqrtf(radius * radius - d2);
        t0= tca - thc; // droite origin -> P0 premier point
        float t1 = tca + thc;
        if (t0 < 0) t0 = t1;
        if (t0 < 0) return false; // si c'est opposé
        return true;
    }
};

Vec3 castRay(const Vec3 & ray , const Vec3 & dir  ,  Sphere & sphere){
    float sphere_dist = std::numeric_limits<float>::max();
    float dist;
    if(sphere.isRayIntersect(ray,dir,dist) && dist < sphere_dist){
        return Vec3(0.2, 0.7, 0.8);
    }
    return Vec3(0.4, 0.4, 0.3);
}

void display(Sphere & sphere){
    const int width = 1024;
    const int height = 768;
    const float ratio = width / (float) height;
    cout << ratio;
    Vec3 ** data = new Vec3 * [height];
    for(int y = 0;y<height;y++){
        data[y] = new Vec3[width];
        for(int x = 0;x<width;x++){

            // world to camera
            float Px = (2 * ((x + 0.5) / width) - 1) * tan(90 / 2 * M_PI / 180) * ratio;
            float Py = (1 - 2 * ((y + 0.5) / height) * tan(90 / 2 * M_PI / 180));
            //direction rayon
            Vec3 dir = Vec3(Px,Py,-1).normalize();
            data[y][x] = castRay(Vec3(0,0,0),dir,sphere);
        }
    }
    ofstream file;
    file.open("./file2.ppm", std::ofstream::out | std::ofstream::binary);
    file << "P6\n" << width << " " << height << "\n255\n";
    for(int y = 0;y<height;y++){
        for(int x = 0;x<width;x++){
            file << (char)data[y][x].clampX(); // clamp
            file << (char)data[y][x].clampY();
            file << (char)data[y][x].clampZ();
        }
    }
    file.close();



}
int main() {
    Sphere sphere(Vec3(-3, 5, -20), 8);
    display(sphere);
    return 0;
}
