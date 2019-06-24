#pragma once
#include <Vec3.h>
#include <Ray.h>

namespace toyrenderer{

class Sphere
{
private:
    Vec3 m_center;
    float m_radius;
public:
    Sphere():m_center(Vec3(0,0,0)), m_radius(0){};
    Sphere(Vec3 center, float radius) : m_center(center), m_radius(radius){};

    bool isIntersecting(const Ray& ray) const
    {
        Vec3 origin2center = ray.origin() - m_center;
        float a = ray.getDirection().dot(ray.getDirection());
        float b = 2.0f * origin2center.dot(ray.getDirection());
        float discriminant = b*b - 4*a*c;
        return (discriminant>0);
    }

};



}
