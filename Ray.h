#pragma once
#include "Vec3.h"
#include "limits"

namespace ToyRenderer{

class Ray{
    private:
        Vec3 m_origin;
        Vec3 m_direction;
    public:
        Ray(){};
        Ray(const Vec3 a, const Vec3 b)
        {
            m_origin = a;
            m_direction = b;
        }
        
        Vec3 getDirection() const
        {
            return m_direction;
        }

        Vec3 getOrigin() const
        {
            return m_origin;
        }

        Vec3 pointAtT(float t) const
        {
            return m_origin + t * m_direction;
        }
};

}
