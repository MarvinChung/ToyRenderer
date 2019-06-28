#pragma once
#include "Vec3.h"
#include "Ray.h"
namespace toyrenderer{
class hit_record
{
    public:
        float t;
        Vec3 p;
        Vec3 normal;
};

class Hitable
{
    public:
        virtual bool isIntersecting(const Ray& input_ray, float tmin, float tmax, hit_record& rec) const = 0;

};
}