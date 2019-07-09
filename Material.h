
#pragma once
#include "Ray.h"
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

inline float schlick(float cosine, float ref_idx)
{
    float r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + ( 1 - r0) * std::pow( (1-cosine), 5);
}

inline Vec3 random_in_unit_sphere()
{
    Vec3 p;
    do {
        p = 2.0 * Vec3(drand48(), drand48(), drand48()) - Vec3(1,1,1) ;
    } while(p.sqaredLength() >= 1.0);
    return p;
}

inline Vec3 reflect(const Vec3& v, const Vec3& n)
{
    return v - 2 * v.dot(n) * n ;
}

inline bool refract(const Vec3& v, const Vec3& n, float ni_over_nt, Vec3& refracted)
{
	Vec3 uv = v.unit_vector();
	float dt = uv.dot(n);
	float discriminant = 1.0 - ni_over_nt * ni_over_nt * (1.0 - dt*dt);
	if(discriminant > 0)
	{
		refracted = ni_over_nt*(uv - n*dt) - n*std::sqrt(discriminant);
		return true;
	}
	else
		return false;
}
class Material
{
    public:
        virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const = 0;
};


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
/*
class Dielectric : public Material
{
    public:
        float m_ref_idx;
        Dielectric(float ri) : m_ref_idx(ri) {}
        virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const
        {
            Vec3 outward_normal;
            Vec3 reflected = reflect(r_in.getDirection(), rec.normal);
            float ni_over_nt;
            attenuation = Vec3(1.0, 1.0, 1.0);
            Vec3 refracted;
            float reflect_prob;
            float cosine;
            if ( r_in.getDirection().dot(rec.normal) > 0 )
            {
                outward_normal = -rec.normal;
                ni_over_nt = m_ref_idx;
                cosine = r_in.getDirection().dot(rec.normal) / r_in.getDirection().length();
                cosine = std::sqrt(1 - m_ref_idx*m_ref_idx*(1-cosine*cosine));
            }
            else
            {
                outward_normal = rec.normal;
                ni_over_nt = 1.0 / m_ref_idx;
                cosine = -r_in.getDirection().dot(rec.normal) / r_in.getDirection().length();
            }

            if( refract(r_in.getDirection(), outward_normal, ni_over_nt, refracted)) {
                reflect_prob = schlick(cosine, m_ref_idx);
            }
            else
            {
                //scattered = Ray(rec.p, reflected);
                reflect_prob = 1.0;
            }

            if(drand48() < reflect_prob)
            {
                scattered = Ray(rec.p, reflected);
            }
            else
            {
                scattered = Ray(rec.p, refracted);
            }

            return true;
        }
};
*/
class Dielectric : public Material { 
    public:
        Dielectric(float ri) : ref_idx(ri) {}
        virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const  {
             Vec3 outward_normal;
             Vec3 reflected = reflect(r_in.getDirection(), rec.normal);
             float ni_over_nt;
             attenuation = Vec3(1.0, 1.0, 1.0); 
             Vec3 refracted;
             float reflect_prob;
             float cosine;
             if (r_in.getDirection().dot(rec.normal) > 0) {
                  outward_normal = -rec.normal;
                  ni_over_nt = ref_idx;
         //         cosine = ref_idx * dot(r_in.direction(), rec.normal) / r_in.direction().length();
                  cosine = r_in.getDirection().dot(rec.normal) / r_in.getDirection().length();
                  cosine = sqrt(1 - ref_idx*ref_idx*(1-cosine*cosine));
             }
             else {
                  outward_normal = rec.normal;
                  ni_over_nt = 1.0 / ref_idx;
                  cosine = - r_in.getDirection().dot(rec.normal) / r_in.getDirection().length();
             }
             if (refract(r_in.getDirection(), outward_normal, ni_over_nt, refracted)) 
                reflect_prob = schlick(cosine, ref_idx);
             else 
                reflect_prob = 1.0;
             if (drand48() < reflect_prob) 
                scattered = Ray(rec.p, reflected);
             else 
                scattered = Ray(rec.p, refracted);
             return true;
        }

        float ref_idx;
};

}
