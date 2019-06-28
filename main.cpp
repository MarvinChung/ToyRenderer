#include <iostream>
#include "Sphere.h"
#include "HitableList.h"
#include "limits"
#include "Camera.h"

#include <time.h>
#include <cstdlib>

using namespace toyrenderer;
Vec3 color(const Ray& r, Hitable *world)
{
    hit_record rec;
    if(world->isIntersecting(r, 0.0f, std::numeric_limits<float>::max(), rec))
        return 0.5 * Vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1 );
    else
    {
        Vec3 unit_direction = r.getDirection().unit_vector();
        float t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
    }

}

float rand0_1()
{
    srand( time(NULL) );
    float x = (float) rand() / (RAND_MAX + 1.0);
    return x;
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

    Hitable *list[2];
    list[0] = new Sphere(Vec3(0, 0, -1), 0.5);
    list[1] = new Sphere(Vec3(0, -100.5, -1), 100);
    Hitable *world = new HitableList(list, 2);
    Camera camera;



    for(int i = ny-1; i >=0 ; i--)
    {
        for(int j = 0; j < nx ;j++)
        {
            Vec3 col(0, 0, 0);
            for(int s = 0; s < ns; s++)
            {
                real u = real(i + rand0_1()) / real(nx);
                real v = real(j + rand0_1()) / real(ny);
                Ray r = camera.getRay(u, v);
                Vec3 p = r.pointAtT(2.0);
                col += color(r, world);
            }
            col /= float(ns);

            int ir = int(255.99 * col.x());
            int ig = int(255.99 * col.y()); 
            int ib = int(255.99 * col.z());

            std::cout << ir << " " << ig << " " << ib << std::endl;
        }
    }
    return 0;
}
