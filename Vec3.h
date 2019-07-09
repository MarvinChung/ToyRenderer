#pragma once
#include<iostream>
#include <cmath>

namespace ToyRenderer
{


class Vec3
{
    public:
        float m_e[3];
        
        Vec3(){}
        Vec3(float a, float b, float c)
        {
            m_e[0] = a;
            m_e[1] = b;
            m_e[2] = c;
        }

        inline float x() const
        {
            return m_e[0];
        }

        inline float y() const
        {
            return m_e[1];
        }

        inline float z() const
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

        inline float sqaredLength() const
        {
            return m_e[0] * m_e[0] + m_e[1] * m_e[1] + m_e[2] * m_e[2];
        }

        inline float length() const
        {
            return std::sqrt( sqaredLength() );
        }

        inline Vec3 unit_vector() const
        {
            float k = 1.0/length();
            Vec3 temp;
            temp.m_e[0] = m_e[0] * k;
            temp.m_e[1] = m_e[1] * k;
            temp.m_e[2] = m_e[2] * k;
            return temp;
        }

        inline float dot(const Vec3& rhs) const
        {
            return (this->m_e[0]*rhs.m_e[0] + this->m_e[1]*rhs.m_e[1] + this->m_e[2]*rhs.m_e[2]);
        }

        inline Vec3 cross(const Vec3& rhs) const
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
    os << t.m_e[0] << " " << t.m_e[1] <<" " << t.m_e[2];
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

inline Vec3 operator*(float t, const Vec3& v)
{
    return Vec3(t*v.m_e[0], t*v.m_e[1], t*v.m_e[2]);
}

inline Vec3 operator*(const Vec3& v, float t)
{
    return Vec3(t*v.m_e[0], t*v.m_e[1], t*v.m_e[2]);
}

inline Vec3 operator*(const Vec3& a, const Vec3& b)
{
    return Vec3(a.m_e[0] * b.m_e[0], a.m_e[1] * b.m_e[1], a.m_e[2] * b.m_e[2]);
}

inline Vec3 operator/(const Vec3& v, float t)
{
    return Vec3(v.m_e[0]/t, v.m_e[1]/t, v.m_e[2]/t);
}


}
