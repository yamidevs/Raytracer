//
// Created by yamisaaf on 06/02/2020.
//

#ifndef RAYTRACER_IMAGE_H
#define RAYTRACER_IMAGE_H

#include <string>
namespace Raytracer{

    struct RGB{
        float r,g,b;
        RGB(){}
        RGB(float _r , float _g , float _b) : r(_r) , g(_g) , b(_b){}
    };
    class Image {
    private:
        Image operator=(Image &img) =  delete;
        RGB  ** datas;
    public:
        int width, height;
        Image( int _width , int _height);
        ~Image();
        void Save(std::string name);
        void Update(int y , int x , RGB color);
    };
}

#endif //RAYTRACER_IMAGE_H
