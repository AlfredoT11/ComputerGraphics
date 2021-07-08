#ifndef MATHFUN_H
#define MATHFUN_H

#include "Vector.hpp"

class OrthonormalBasis{
    public:
        Vector3 v[3];

        OrthonormalBasis(Vector3 v1, Vector3 v2, Vector3 v3);
        static OrthonormalBasis newCoordinateFrameBasis(Vector3 view);
};

float determinant3x3(float matrix[3][3]);

#endif