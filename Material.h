#pragma once
#include "Ray.h"
#include "Vec3.h"
#include <time.h>

namespace ToyRenderer{
class Material;

class HitRecord{
    public:
        float t;
        Vec3 p;
        Vec3 normal;
        Material *mat_ptr;
};


inline float rand0_1()
{
    srand( time(NULL) );
    float x = (float) rand() / (RAND_MAX + 1.0);
    return x;
}

inline Vec3 random_in_unit_sphere()
{
    Vec3 p;
    do {
        p = 2.0 * Vec3(rand0_1(), rand0_1(), rand0_1()) - Vec3(1,1,1) ;
    } while(p.sqaredLength() >= 1.0);
    return p;
}

inline Vec3 reflect(const Vec3& v, const Vec3& n)
{
    return v - 2 * v.dot(n) * n ;
}

class Material
{
    public:
        virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const = 0;
};

}
