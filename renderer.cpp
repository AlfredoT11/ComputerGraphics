#include "iostream"
#include "renderer.hpp"
#include "figures.hpp"

using namespace std;

void renderSceneConsole(int l, int r, int b, int t, OrthonormalBasis basis, Vector3 e, Vector3 lightD){

    Vector3 normal;

    char const lightValues[12] = {'.', ',', '-', '~', ':', ';', '=', '!', '*', '#', '$', '@'};

    //Vector3 centro1 = {0.0, 0.0, 0.0};
    //Sphere sphere1 = {centro1, 20};

    //Vector3 centro2 = {-4.0, -6.0, 6.0};
    //Sphere sphere2 = {centro2, 0};

    //Vector3 centro3 = {0, -3.5, -7.5};
    //Sphere sphere3 = {centro3, 0};

    //Sphere spheres[3] = {sphere1, sphere2, sphere3};

    Vector3 a1 = {5, 10, 15};
    Vector3 b1 = {-12, -25, 15};
    Vector3 c1 = {0, -15, -15};

    Triangle triangle1 = Triangle{c1, b1, a1};
    Triangle shapes[1] = {triangle1};

    float horizontalPixels = 60.0;
    float verticalPixels = 60.0;

    for(float i = 0.0; i < horizontalPixels; i+=1){
        for(float j = 0.0; j < verticalPixels; j+=1){
            float u = l + (r-l)*(i+0.5)/horizontalPixels;
            float v = b + (t-b)*(j+0.5)/verticalPixels;

            /*cout << "i:" << i << endl;
            cout << "j:" << j << endl;
            cout << "u:" << u << endl;
            cout << "v:" << v << endl;
            cout << endl;*/

            Vector3 rayOrigin = Vector3::add(e, Vector3::multiplication(basis.v[0], u));
            rayOrigin.add(Vector3::multiplication(basis.v[1], v));
            Ray ray = Ray(rayOrigin, Vector3::multiplication(basis.v[2], -1));

            bool hit = false;

            for(int k = 0; k < 1; k++){

                //normal = intersectSphere(ray, spheres[k]);
                //normal = spheres[k].intersect(ray);
                normal = shapes[k].intersect(ray);
                
                if(Vector3::magnitude(normal) > 0.0){
                    hit = true;
                    break;
                }
            }

            if(hit){
                float surfaceColor = 12*Vector3::dotProduct(normal, lightD);
                if(surfaceColor > 0.0){
                    char rendererValue = lightValues[int(surfaceColor)];
                    cout << rendererValue;
                    //cout << 'o';
                }else{
                    cout << '.';
                }
                
            }else{
                cout << ' ';
            }
            cout << ' ';

        }
        cout << endl;        
    }

}