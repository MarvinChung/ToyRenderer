#pragma once
#include "Ray.h"
#include <cmath>

namespace ToyRenderer{
const double PI =3.141592653589793238463;

inline Vec3 random_in_unit_disk()
{
	Vec3 p;
	do{
		p = 2.0 * Vec3(drand48(), drand48(), 0) - Vec3(1, 1, 0);
	} while(p.dot(p) >= 1.0);
	return p;
}

class Camera
{
    public:
        Vec3 m_origin;
        Vec3 m_lower_left_corner;
        Vec3 m_horizontal;
        Vec3 m_vertical;
		float m_lens_radius;
		Vec3 m_u, m_v, m_w;

		// Camera()
		// {
		// 	m_lower_left_corner = Vec3(-2.0, -1.0, -1.0);
		// 	m_horizontal = Vec3(4.0, 0.0, 0.0);
		// 	m_vertical = Vec3(0.0, 2.0, 0.0);
		// 	m_origin = Vec3(0.0, 0.0, 0.0);
		// }

  //       Ray getRay(float s, float t)
  //       {
  //           return Ray(m_origin, m_lower_left_corner + s * m_horizontal + t * m_vertical - m_origin);
  //       }
		/*
		
        Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float vfov, float aspect){
			float theta = vfov * PI/180;
			float half_height = tan(theta/2);
			float half_width = aspect * half_height;
			m_origin = lookfrom;
			m_w = (lookfrom - lookat).unit_vector();
			m_u = vup.cross(m_w).unit_vector();
			m_v = m_w.cross(m_u);
			m_lower_left_corner = m_origin - half_width*m_u - half_height*m_v - m_w;
            m_horizontal = 2 * half_width *  m_u;
            m_vertical = 2 * half_height *  m_v;
        }  
        Ray getRay(float s, float t)
        {
            return Ray(m_origin, m_lower_left_corner + s * m_horizontal + t * m_vertical - m_origin);
        }
		
		*/
        Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, float vfov, float aspect, float aperture, float focus_dist){
			m_lens_radius = aperture / 2; 
			float theta = vfov * PI/180;
			float half_height = tan(theta/2);
			float half_width = aspect * half_height;
			m_origin = lookfrom;
			m_w = (lookfrom - lookat).unit_vector();
			m_u = vup.cross(m_w).unit_vector();
			m_v = m_w.cross(m_u);
			m_lower_left_corner = m_origin - half_width*focus_dist*m_u - half_height*focus_dist*m_v - focus_dist*m_w;
            m_horizontal = 2 * half_width * focus_dist * m_u;
            m_vertical = 2 * half_height * focus_dist * m_v;
        }  
        Ray getRay(float s, float t)
        {
			Vec3 rd = m_lens_radius * random_in_unit_disk();
			Vec3 offset = m_u * rd.x() + m_v * rd.y();
            return Ray(m_origin + offset, m_lower_left_corner + s * m_horizontal + t * m_vertical - m_origin - offset);
        }
        
		
};
}
