#ifndef VECTOR_H
#define VECTOR_H

class Vector3{
    public:
        float e[3];

        Vector3();
        Vector3(float x, float y, float z);
        void add(Vector3 b);
        void sub(Vector3 b);
        void multiplication(float a);
        void division(float a);
        void showValue();
        
        
        static Vector3 add(Vector3 a, Vector3 b);
        static Vector3 sub(Vector3 a, Vector3 b);
        static Vector3 multiplication(Vector3 a, float c);
        static Vector3 division(Vector3 a, float c);
        static float magnitude(Vector3 a);
        static float dotProduct(Vector3 a, Vector3 b);
        static Vector3 crossProduct(Vector3 a, Vector3 b);
        
};

#endif