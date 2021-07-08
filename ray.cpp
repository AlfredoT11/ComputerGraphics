#include "ray.hpp"

Ray::Ray(Vector3 o, Vector3 d){
    origin = Vector3{o.e[0], o.e[1], o.e[2]};
    direction = Vector3{d.e[0], d.e[1], d.e[2]};
}