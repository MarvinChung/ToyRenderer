#pragma once
#include "Ray.h"
#include "Material.h"

namespace ToyRenderer{

class Metal : public Material{
    public:
        Vec3 m_albedo;
        float m_fuzz;
        Metal(const Vec3& a, float f) : m_albedo(a) {
            if(f < 1)
                m_fuzz = f;
            else
            {
                m_fuzz = 1;
            }
            
        };
        virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const
        {
            Vec3 reflected = reflect(r_in.getDirection().unit_vector(), rec.normal);
            scattered = Ray(rec.p, reflected + m_fuzz * random_in_unit_sphere());
            attenuation = m_albedo;
            return scattered.getDirection().dot(rec.normal) > 0;
        }
};

}


