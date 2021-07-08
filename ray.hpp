#ifndef RAY_H
#define RAY_H
#include "Vector.hpp"

class Ray
{
    public:
        Vector3 origin;
        Vector3 direction;

        Ray(Vector3 o, Vector3 d);

};

#endif