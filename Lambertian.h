#pragma once
#include "Material.h"
#include "Vec3.h"
#include <time.h>

namespace ToyRenderer{

class Lambertian : public Material
{
    public:
        Vec3 m_albedo;
        Lambertian(const Vec3& a) : m_albedo(a) {}


        virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const
        {
            Vec3 target = rec.p + rec.normal + random_in_unit_sphere();
            scattered = Ray(rec.p, target - rec.p);
            attenuation = m_albedo;
            return true;
        }
};
}

