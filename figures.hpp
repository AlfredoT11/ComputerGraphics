#ifndef FIGURES_H
#define FIGURES_H

#include "Vector.hpp"
#include "ray.hpp"
#include "rgb.hpp"

class Shape{
    public:
        virtual Vector3 intersect(Ray ray);
};


class Sphere : public Shape{
    public:
        Vector3 origin;
        float radius;
        RGBColor color;

        Sphere(Vector3 o, float r);
        Vector3 intersect(Ray ray);
};

class Triangle : public Shape{
    public:
        Vector3 v[3];
        RGBColor color[3];

        Triangle(Vector3 a, Vector3 b, Vector3 c);
        Vector3 intersect(Ray ray);

};

#endif