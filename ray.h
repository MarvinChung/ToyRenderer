#include "vec3.h"

namespace toyrenderer{

class ray{
    private:
        vec3 m_origin;
        vec3 m_direction;
    public:
        ray(){};
        ray(const vec3& a, const vec3& b)
        {
            m_origin = a;
            m_direction = b;
        }
        
        vec3 getDirection() const
        {
            return m_direction;
        }

        vec3 getOrigin() const
        {
            return m_origin;
        }

        vec3 pointAtT(float t) const
        {
            return m_origin + t * m_direction;
        }
};

}