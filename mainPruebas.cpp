#include "iostream"
#include "mathFun.hpp"
#include "renderer.hpp"

using namespace std;

//cl /EHsc mainPruebas.cpp Vector.cpp mathFun.cpp ray.cpp figures.cpp rayTracer.cpp renderer.cpp
//cl /EHsc /Od /c <nombre>.cpp

int main(){

    /*
    Vector3 x{2, 0, 1};
    Vector3 y{0, -3, 1};
    Vector3 c = Vector3::crossProduct(x, y);

    c.showValue();
    float magnitudeC = Vector3::magnitude(c);
    cout << "Magnitude: " << magnitudeC << endl;

    OrthonormalBasis::newCoordinateFrameBasis(c);

    Vector3 origin{1, -2, 3};

    cout << "Rayo: " << endl;
    for(float i = 0; i < 2.0; i+=0.2){
        Vector3 p{origin.e[0], origin.e[1], origin.e[2]};
        Vector3 direction{c.e[0], c.e[1], c.e[2]};
        direction.multiplication(i);
        p.sub(direction);
        p.showValue();
    }

    cout << endl;
    cout << endl;
    */

    Vector3 direction = {-1.0, 0.0, 0.0};
    Vector3 viewPos = {1.0, 0.0, 0.0};
    OrthonormalBasis orthonormalZ = OrthonormalBasis::newCoordinateFrameBasis(direction);

    float lightX, lightY, lightZ;
    cin >> lightX;
    cin >> lightY;
    cin >> lightZ;

    Vector3 lightDirection = {lightX, lightY, lightZ};
    Vector3 lightDirectionNormal = Vector3::division(lightDirection, Vector3::magnitude(lightDirection));

    /*
    cout << "Basis: " << endl;
    orthonormalZ.v[0].showValue();
    orthonormalZ.v[1].showValue();
    orthonormalZ.v[2].showValue();
    */

    renderSceneConsole(-30, 29, -30, 29, orthonormalZ, viewPos, lightDirectionNormal);

    cout << "Fin." << endl;

    return 0;
}