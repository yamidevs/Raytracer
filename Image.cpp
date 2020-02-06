//
// Created by yamisaaf on 06/02/2020.
//

#include "Image.h"
#include "Vec3.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iostream>
#include <string>

Raytracer::Image::Image( int _width, int _height) {
    this->width = _width;
    this->height = _height;
    this->datas = new Raytracer::RGB * [_height];
    for(int y = 0;y<height;y++){
        datas[y] = new Raytracer::RGB[width];
        for(int x = 0;x<width;x++) {
            datas[y][x].r = 255.f;
            datas[y][x].g = 0.f;
            datas[y][x].b = 0.f;
        }
    }
}

void Raytracer::Image::Save(std::string name) {
    std::ofstream file;
    file.open(name, std::ofstream::out | std::ofstream::binary);
    file << "P6\n" << width << " " << height << "\n255\n";
    for(int y = 0;y<height;y++){
        for(int x = 0;x<width;x++){
              file << (char)datas[y][x].r;
              file << (char)datas[y][x].g;
              file << (char)datas[y][x].b;

        }
    }
    file.close();
}

void Raytracer::Image::Update(int y , int x , RGB color){
    datas[y][x] = color;
}

Raytracer::Image::~Image() {
    for(int y = 0;y<height;y++){
        delete[] datas[y];
    }
    delete[] datas;
}