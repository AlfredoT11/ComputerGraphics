#include "iostream"
#include "math.h"
#include "figures.hpp"
#include "mathFun.hpp"
#include "ray.hpp"

using namespace std;

Vector3 Shape::intersect(Ray ray){
    return Vector3{0.0, 0.0, 0.0};
}

Triangle::Triangle(Vector3 a, Vector3 b, Vector3 c){
    v[0] = a;
    v[1] = b;
    v[2] = c;
}

Vector3 Triangle::intersect(Ray ray){

    //cout << "Hola :D" << endl;

    float xa_xb = v[0].e[0] - v[1].e[0];
    float ya_yb = v[0].e[1] - v[1].e[1];
    float za_zb = v[0].e[2] - v[1].e[2];
    float xa_xc = v[0].e[0] - v[2].e[0];
    float ya_yc = v[0].e[1] - v[2].e[1];
    float za_zc = v[0].e[2] - v[2].e[2];
    float xa_xe = v[0].e[0] - ray.origin.e[0];
    float ya_ye = v[0].e[1] - ray.origin.e[1];
    float za_ze = v[0].e[2] - ray.origin.e[2];

    float matrixA[3][3] = {
        {xa_xb, xa_xc, ray.direction.e[0]},
        {ya_yb, ya_yc, ray.direction.e[1]},
        {za_zb, za_zc, ray.direction.e[2]}
    };

    float matrixBeta[3][3] = {
        {xa_xe, xa_xc, ray.direction.e[0]},
        {ya_ye, ya_yc, ray.direction.e[1]},
        {za_ze, za_zc, ray.direction.e[2]}
    };

    float matrixGamma[3][3] = {
        {xa_xb, xa_xe, ray.direction.e[0]},
        {ya_yb, ya_ye, ray.direction.e[1]},
        {za_zb, za_ze, ray.direction.e[2]}
    };

    float matrixT[3][3] = {
        {xa_xb, xa_xc, xa_xe},
        {ya_yb, ya_yc, ya_ye},
        {za_zb, za_zc, za_ze}
    };

    float A = determinant3x3(matrixA);
    float t = determinant3x3(matrixT)/A;

    float gamma = determinant3x3(matrixGamma)/A;
    if(gamma < 0 || gamma > 1){
        return Vector3{0.0, 0.0, 0.0};
    }

    float beta = determinant3x3(matrixBeta)/A;
    if(beta < 0 || beta > 1 - gamma){
        return Vector3{0.0, 0.0, 0.0};
    }

    Vector3 p = Vector3::add(ray.origin, Vector3::multiplication(ray.direction, t));

    Vector3 normal = Vector3::crossProduct(Vector3::sub(v[1], v[0]), Vector3::sub(v[2], v[0]));
    float normalMagnitude = Vector3::magnitude(normal);

    return Vector3::division(normal, normalMagnitude);

}

Sphere::Sphere(Vector3 o, float r){
    origin = Vector3{o.e[0], o.e[1], o.e[2]};
    radius = r;
}

Vector3 Sphere::intersect(Ray ray){

    Vector3 originCenterSub = Vector3::sub(ray.origin, this->origin);
    
    // Calculating discriminant.
    float bPow = pow(Vector3::dotProduct(ray.direction, originCenterSub), 2);
    
    float directionCentersDotP = Vector3::dotProduct(ray.direction, originCenterSub);
    float directionDotP = Vector3::dotProduct(ray.direction, ray.direction);
    float originCenterSubDotP =  Vector3::dotProduct(originCenterSub, originCenterSub);

    float discriminant = pow(directionCentersDotP, 2) - directionDotP*(originCenterSubDotP - pow(this->radius, 2));
    if(discriminant < 0){
        return Vector3{0.0, 0.0, 0.0};
    }

    float t1 = ((-1*directionCentersDotP) + sqrt(discriminant))/directionDotP;
    float t2 = ((-1*directionCentersDotP) - sqrt(discriminant))/directionDotP;
    
    Vector3 p1 = Vector3::add(ray.origin, Vector3::multiplication(ray.direction, t1));
    Vector3 p2 = Vector3::add(ray.origin, Vector3::multiplication(ray.direction, t2));

    Vector3 n1 = Vector3::division(Vector3::sub(p1, this->origin), this->radius);
    Vector3 n2 = Vector3::division(Vector3::sub(p2, this->origin), this->radius);

    /*cout << endl;
    cout << "t1: " << t1 << "p(t) = ";
    p1.showValue();
    cout << "normal = ";
    n1.showValue();
    
    cout << "t2: " << t2 << "p(t) = ";;
    p2.showValue();
    cout << "normal = ";
    n2.showValue();    
    cout << endl;
    */

    return n1;
}
