#include "iostream"
#include "mathFun.hpp"

using namespace std;

OrthonormalBasis::OrthonormalBasis(Vector3 v1, Vector3 v2, Vector3 v3)
{
    v[0] = Vector3{v1.e[0], v1.e[1], v1.e[2]};
    v[1] = Vector3{v2.e[0], v2.e[1], v2.e[2]};
    v[2] = Vector3{v3.e[0], v3.e[1], v3.e[2]};
}


/**
 * Generates a new Orthonormal Basis from view vector.
 * 
 * @param view a Vector3 that specifies the direction of view.
 * @return A new Orthormal basis where z vector is the normilized view vector inversed.
 * 
 */
OrthonormalBasis OrthonormalBasis::newCoordinateFrameBasis(Vector3 view)
{

    float viewMagnitude = Vector3::magnitude(view);
    Vector3 w{view.e[0]*-1/viewMagnitude, view.e[1]*-1/viewMagnitude, view.e[2]*-1/viewMagnitude};
    Vector3 up{0, 1, 0};
    Vector3 u = Vector3::crossProduct(up, w);
    Vector3 v = Vector3::crossProduct(w, u);

    /*
    u.showValue();
    v.showValue();
    w.showValue();
    */

    OrthonormalBasis orthonormalBasis = OrthonormalBasis{u, v, w};
    
    /*
    cout << "Base: " << endl;
    orthonormalBasis.v[0].showValue();
    orthonormalBasis.v[1].showValue();
    orthonormalBasis.v[2].showValue();
    */

    return orthonormalBasis;

}


float determinant3x3(float matrix[3][3]){
    float termA = matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1]);
    float termB = matrix[1][0]*(matrix[0][1]*matrix[2][2] - matrix[2][1]*matrix[0][2]);
    float termC = matrix[2][0]*(matrix[0][1]*matrix[1][2] - matrix[1][1]*matrix[0][2]);

    return termA - termB + termC;
}
