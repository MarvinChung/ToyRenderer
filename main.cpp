#include <iostream>
#include "Vec3.h"
#include "Ray.h"
#include "Sphere.h"

using namespace toyrenderer;
Vec3 color(const Ray& r)
{
    Sphere sphere(Vec3(0,0,0), 0.5);
    if(sphere.isIntersecting(r))
        return Vec3(1,0,0);
    
    Vec3 unit_direction = r.getDirection().unit_vector();
    real t = 0.5*(unit_direction.y()) + 1.0;
    return (1.0-t) * Vec3(1.0, 1.0, 1.0) + t *Vec3(0.5, 0.7, 1.0);

}

int main()
{

    int nx = 200;
    int ny = 100;
    
    std::cout << "P3\n"  << nx << " " << ny << "\n255\n";
    Vec3 lower_left_corner(-2.0, -1.0, -1.0);
    Vec3 horizontal(4.0, 0.0, 0.0);
    Vec3 vertical(0.0, 2.0, 0.0);
    Vec3 origin(0.0, 0.0, 0.0);

    for(int i = ny-1; i >=0 ; i--)
    {
        for(int j = 0; j < nx ;j++)
        {
            real u = real(i) / real(nx);
            real v = real(j) / real(ny);
            Ray r(origin,  lower_left_corner + u * horizontal + v * vertical);
            Vec3 col = color(r);
            int ir = int(255.99 * col.x());
            int ig = int(255.99 * col.y());
            int ib = int(255.99 * col.z());

            std::cout << ir << " " << ig << " " << ib << std::endl;
        }
    }
    return 0;
}
