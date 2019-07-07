#pragma once
#include "Vec3.h"
#include "Ray.h"
#include "Material.h"
namespace ToyRenderer{
class Hitable
{
    public:
        virtual bool isIntersecting(const Ray& input_ray, float tmin, float tmax, HitRecord& rec) const = 0;

};
}