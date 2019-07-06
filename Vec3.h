#pragma once
#include<iostream>
#include <cmath>

namespace ToyRenderer
{

typedef float real;

class Vec3
{
    public:
        real m_e[3];
        
        Vec3(){}
        Vec3(real a, real b, real c)
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
        inline const Vec3& operator+() const
        {
            return *this;
        }
        
        inline Vec3 operator-() const
        {
            return Vec3(-m_e[0], -m_e[1], -m_e[2]);
        }

        //binary operator
        inline Vec3& operator+=(const Vec3& v2)
        {
            m_e[0] += v2.m_e[0];
            m_e[1] += v2.m_e[1];
            m_e[2] += v2.m_e[2];
            return *this;
        }

        inline Vec3& operator-=(const Vec3& v2)
        {
            m_e[0] -= v2.m_e[0];
            m_e[1] -= v2.m_e[1];
            m_e[2] -= v2.m_e[2];
            return *this;
        }

        inline Vec3& operator*=(const Vec3& v2)
        {
            m_e[0] *= v2.m_e[0];
            m_e[1] *= v2.m_e[1];
            m_e[2] *= v2.m_e[2];
            return *this;
        }

        inline Vec3& operator/=(const Vec3& v2)
        {
            m_e[0] /= v2.m_e[0];
            m_e[1] /= v2.m_e[1];
            m_e[2] /= v2.m_e[2];
            return *this;
        }
       
        inline Vec3& operator*=(const float t)
        {
            m_e[0] *= t;
            m_e[1] *= t;
            m_e[2] *= t;
            return *this;
        }

        inline Vec3& operator/=(const float t)
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

        inline Vec3 unit_vector()
        {
            float k = 1.0/sqaredLength();
            Vec3 temp;
            temp.m_e[0] = m_e[0] * k;
            temp.m_e[1] = m_e[1] * k;
            temp.m_e[2] = m_e[2] * k;
            return temp;
        }

        inline real dot(const Vec3& rhs)
        {
            return (this->m_e[0]*rhs.m_e[0] + this->m_e[1]*rhs.m_e[1] + this->m_e[2]*rhs.m_e[2]);
        }

        inline Vec3 cross(const Vec3& rhs)
        {
            return Vec3((this->m_e[1] * rhs.m_e[2] - this->m_e[2] * rhs.m_e[1]),
                        -(this->m_e[0] * rhs.m_e[2] - this->m_e[2] * rhs.m_e[0]),
                        (this->m_e[0] * rhs.m_e[1] - this->m_e[1] * rhs.m_e[0])
                    );
        }

};

//non member operator functions
inline std::istream& operator>>(std::istream& is, Vec3& t) 
{
    is >> t.m_e[0] >> t.m_e[1] >> t.m_e[2];
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Vec3& t)
{
    os << t.m_e[0] << t.m_e[1] << t.m_e[2];
    return os;
}

inline Vec3 operator+(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.m_e[0] + v2.m_e[0], v1.m_e[1] + v2.m_e[1], v1.m_e[2] + v2.m_e[2]);
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.m_e[0] - v2.m_e[0], v1.m_e[1] - v2.m_e[1], v1.m_e[2] - v2.m_e[2]);
}

inline Vec3 operator*(real t, const Vec3& v)
{
    return Vec3(t*v.m_e[0], t*v.m_e[1], t*v.m_e[2]);
}

inline Vec3 operator/(const Vec3& v, real t)
{
    return Vec3(v.m_e[0]/t, v.m_e[1]/t, v.m_e[2]/t);
}


}
