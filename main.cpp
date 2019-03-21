#include <iostream>
#include "vec3.h"
#include "ray.h"

using namespace toyrenderer;
vec3 color(const ray& r)
{
    vec3 unit_direction = unit_vector(r.getDirection());
    real t = 0.5*(unit_direction.y()) + 1.0;
    return (1.0-t) * vec3(1.0, 1.0, 1.0) + t *vec3(0.5, 0.7, 1.0);

}

int main()
{

    int nx = 200;
    int ny = 100;
    
    std::cout << "P3\n"  << nx << " " << ny << "\n255\n";
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    for(int i = ny-1; i >=0 ; i--)
    {
        for(int j = 0; j < nx ;j++)
        {
            real u = real(i) / real(nx);
            real v = real(j) / real(ny);
            ray r(origin,  lower_left_corner + u * horizontal + v * vertical);
            vec3 col = color(r);
            int ir = int(255.99 * col.x());
            int ig = int(255.99 * col.y());
            int ib = int(255.99 * col.z());

            std::cout << ir << " " << ig << " " << ib << std::endl;
        }
    }
    return 0;
}
