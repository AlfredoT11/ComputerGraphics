#include "iostream"
#include <math.h>
#include "Vector.hpp"

using namespace std;

Vector3::Vector3(){
    
}

Vector3::Vector3(float x, float y, float z)
{
    e[0] = x;
    e[1] = y;
    e[2] = z;
}

void Vector3::add(Vector3 b)
{
    e[0] += b.e[0];
    e[1] += b.e[1];
    e[2] += b.e[2];
}

void Vector3::sub(Vector3 b)
{
    e[0] -= b.e[0];
    e[1] -= b.e[1];
    e[2] -= b.e[2];
}

void Vector3::multiplication(float a)
{
    e[0] *= a;
    e[1] *= a;
    e[2] *= a;
}

void Vector3::division(float a)
{
    e[0] /= a;
    e[1] /= a;
    e[2] /= a;
}

void Vector3::showValue()
{
    cout << "[" << e[0] << "," << e[1] << "," << e[2] << "]" << endl;
}

Vector3 Vector3::add(Vector3 a, Vector3 b)
{
    Vector3 c = {a.e[0] + b.e[0], a.e[1] + b.e[1], a.e[2] + b.e[2]};
    return c;
}

Vector3 Vector3::sub(Vector3 a, Vector3 b)
{
    Vector3 c = {a.e[0] - b.e[0], a.e[1] - b.e[1], a.e[2] - b.e[2]};
    return c;
}

Vector3 Vector3::multiplication(Vector3 a, float c)
{
    Vector3 b = {c*a.e[0], c*a.e[1], c*a.e[2]};
    return b;
}
Vector3 Vector3::division(Vector3 a, float c)
{
    Vector3 b = {a.e[0]/c, a.e[1]/c, a.e[2]/c};
    return b;    
}

float Vector3::magnitude(Vector3 a)
{
    float magnitude = pow(a.e[0], 2.0) + pow(a.e[1], 2.0) + pow(a.e[2], 2.0);
    return sqrt(magnitude);
}

float Vector3::dotProduct(Vector3 a, Vector3 b){
    return a.e[0] * b.e[0] + a.e[1] * b.e[1] + a.e[2] * b.e[2];
}

Vector3 Vector3::crossProduct(Vector3 a, Vector3 b)
{    
    float x = a.e[1]*b.e[2] - a.e[2]*b.e[1];
    float y = a.e[2]*b.e[0] - a.e[0]*b.e[2];
    float z = a.e[0]*b.e[1] - a.e[1]*b.e[0];
    Vector3 c = {x, y, z};
    return c;

}
