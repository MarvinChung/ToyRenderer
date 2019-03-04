#pragma once
#include<iostream>
#include <cmath>

namespace toyrenderer
{

typedef float real;

class vec3
{
    public:
        real m_e[3];
        
        vec3(){}
        vec3(real a, real b, real c)
        {
            m_e[0] = a;
            m_e[1] = b;
            m_e[2] = c;
        }

        inline real x() const
        {
            return m_e[0];
        }

        inline real y() const
        {
            return m_e[1];
        }

        inline real z() const
        {
            return m_e[2];
        }

        //unary operator
        inline const vec3& operator+() const
        {
            return *this;
        }
        
        inline vec3 operator-() const
        {
            return vec3(-m_e[0], -m_e[1], -m_e[2]);
        }

        //binary operator
        inline vec3& operator+=(const vec3& v2)
        {
            m_e[0] += v2.m_e[0];
            m_e[1] += v2.m_e[1];
            m_e[2] += v2.m_e[2];
            return *this;
        }

        inline vec3& operator-=(const vec3& v2)
        {
            m_e[0] -= v2.m_e[0];
            m_e[1] -= v2.m_e[1];
            m_e[2] -= v2.m_e[2];
            return *this;
        }

        inline vec3& operator*=(const vec3& v2)
        {
            m_e[0] *= v2.m_e[0];
            m_e[1] *= v2.m_e[1];
            m_e[2] *= v2.m_e[2];
            return *this;
        }

        inline vec3& operator/=(const vec3& v2)
        {
            m_e[0] /= v2.m_e[0];
            m_e[1] /= v2.m_e[1];
            m_e[2] /= v2.m_e[2];
            return *this;
        }
       
        inline vec3& operator*=(const float t)
        {
            m_e[0] *= t;
            m_e[1] *= t;
            m_e[2] *= t;
            return *this;
        }

        inline vec3& operator/=(const float t)
        {
            m_e[0] /= t;
            m_e[1] /= t;
            m_e[2] /= t;
            return *this;
        }

        inline real sqaredLength() const
        {
            return m_e[0] * m_e[0] + m_e[1] * m_e[1] + m_e[2] * m_e[2];
        }

        inline real length() const
        {
            return std::sqrt( sqaredLength() );
        }

        inline void make_unit_vector()
        {
            float k = 1.0/sqaredLength();
            m_e[0] *= k;
            m_e[1] *= k;
            m_e[2] *= k;
        }

        inline real dot(const vec3& rhs)
        {
            return (this->m_e[0]*rhs.m_e[0] + this->m_e[1]*rhs.m_e[1] + this->m_e[2]*rhs.m_e[2]);
        }

        inline vec3 cross(const vec3& rhs)
        {
            return vec3((this->m_e[1] * rhs.m_e[2] - this->m_e[2] * rhs.m_e[1]),
                        -(this->m_e[0] * rhs.m_e[2] - this->m_e[2] * rhs.m_e[0]),
                        (this->m_e[0] * rhs.m_e[1] - this->m_e[1] * rhs.m_e[0])
                    );
        }
};

//non member operator functions
inline std::istream& operator>>(std::istream& is, vec3& t) 
{
    is >> t.m_e[0] >> t.m_e[1] >> t.m_e[2];
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const vec3& t)
{
    os << t.m_e[0] << t.m_e[1] << t.m_e[2];
    return os;
}

inline vec3 operator+(const vec3& v1, const vec3& v2)
{
    return vec3(v1.m_e[0] + v2.m_e[0], v1.m_e[1] + v2.m_e[1], v1.m_e[2] + v2.m_e[2]);
}

inline vec3 operator-(const vec3& v1, const vec3& v2)
{
    return vec3(v1.m_e[0] - v2.m_e[0], v1.m_e[1] - v2.m_e[1], v1.m_e[2] - v2.m_e[2]);
}

inline vec3 operator*(real t, const vec3& v)
{
    return vec3(t*v.m_e[0], t*v.m_e[1], t*v.m_e[2]);
}

inline vec3 operator/(const vec3& v, real t)
{
    return vec3(v.m_e[0]/t, v.m_e[1]/t, v.m_e[2]/t);
}


}
