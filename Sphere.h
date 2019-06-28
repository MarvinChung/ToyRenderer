#pragma once
#include "Hitable.h"

namespace toyrenderer{

class Sphere : public Hitable
{
private:
    Vec3 m_center;
    float m_radius;
public:
    Sphere():m_center(Vec3(0,0,0)), m_radius(0){};
    Sphere(Vec3 center, float radius) : m_center(center), m_radius(radius){};
    Vec3 getCenter() const
    {
        return m_center;
    }

    float getRadius() const
    {
        return m_radius;
    }

    bool isIntersecting(const Ray& ray, float tmin, float tmax, hit_record& rec) const
    {
        Vec3 origin2center = ray.getOrigin() - m_center;
        float a = ray.getDirection().dot(ray.getDirection());
        float b = 2.0f * origin2center.dot(ray.getDirection());
        float c = origin2center.dot(origin2center) - m_radius * m_radius;
        float discriminant = b*b - 4*a*c;

        if(discriminant>0)
        {
            float temp = (-b - std::sqrt(b*b - a*c)) / a;
            if(temp < tmin && temp > tmax)
            {
                rec.t = temp;
                rec.p = ray.pointAtT(rec.t);
                rec.normal = (rec.p - m_center)/m_radius;
                return true;
            }
            temp = (-b - std::sqrt(b*b - a*c)) / a;
            if(temp < tmax && temp > tmin)
            {
                rec.t = temp;
                rec.p = ray.pointAtT(rec.t);
                rec.normal = (rec.p - m_center) / m_radius;
                return true;
            }
        }
        return false;
    }


};



}