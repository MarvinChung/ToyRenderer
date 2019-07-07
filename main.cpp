#include <iostream>
#include "Sphere.h"
#include "HitableList.h"
#include "Metal.h"
#include "Lambertian.h"
#include "Camera.h"
#include "Vec3.h"

#include <time.h>
#include <cstdlib>
#include <limits>

using namespace ToyRenderer;

Vec3 color(const Ray& r, Hitable *world, int depth)
{
    HitRecord rec;
    if(world->isIntersecting(r, 0.001f, std::numeric_limits<float>::max(), rec))
    {
        Ray scattered;
        Vec3 attenuation;
        if(depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered))
        {
           	//std::cout << "atten" << attenuation << std::endl;
		   	return attenuation * color(scattered, world, depth + 1);
        }
        else
        {
            return Vec3(0,0,0);
        }
    }
    else
    {
        Vec3 unit_direction = r.getDirection().unit_vector();
        float t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
    }

}

int main()
{

    int nx = 200;
    int ny = 100;
    int ns = 100;
    
    std::cout << "P3\n"  << nx << " " << ny << "\n255\n";
    Vec3 lower_left_corner(-2.0, -1.0, -1.0);
    Vec3 horizontal(4.0, 0.0, 0.0);
    Vec3 vertical(0.0, 2.0, 0.0);
    Vec3 origin(0.0, 0.0, 0.0);

    Hitable *list[4];
    list[0] = new Sphere(Vec3(0, 0, -1), 0.5, new Lambertian(Vec3(0.8, 0.3, 0.3)));
    list[1] = new Sphere(Vec3(0, -100.5, -1), 100, new Lambertian(Vec3(0.8, 0.8, 0.0)));
    list[2] = new Sphere(Vec3(1, 0, -1), 0.5, new Metal(Vec3(0.8, 0.6, 0.2), 0.3f));
    list[3] = new Sphere(Vec3(-1, 0, -1), 0.5, new Metal(Vec3(0.8, 0.8, 0.8), 0.1f));

    Hitable *world = new HitableList(list, 4);
    Camera camera;



    for(int j = ny-1; j >=0 ; j--)
    {
        for(int i = 0; i < nx ; i++)
        {
            Vec3 col(0, 0, 0);
            for(int s = 0; s < ns; s++)
            {
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);
                Ray r = camera.getRay(u, v);
                Vec3 p = r.pointAtT(2.0);
                col += color(r, world, 0);
            }
            col /= float(ns);
            col = Vec3( std::sqrt(col.x()), std::sqrt(col.y()), std::sqrt(col.z()));
            int ir = int(255.99 * col.x());
            int ig = int(255.99 * col.y()); 
            int ib = int(255.99 * col.z());

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    return 0;
}
