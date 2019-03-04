#include <iostream>
#include "vec3.h"


int main()
{
    using namespace toyrenderer;
    int nx = 200;
    int ny = 100;
    std::cout << "P3\n"  << nx << ny << "n\255\n";
    for(int i = ny-1; i >=0 ; i--)
    {
        for(int j = 0; j < nx ;j++)
        {
            vec3 col( real(i)/real(nx), real(j)/real(ny), 0.2);
            int ir = int(255.99 * col.x());
            int ig = int(255.99 * col.y());
            int ib = int(255.99 * col.z());

            std::cout << ir << ig << ib << std::endl;
        }
    }
    return 0;
}
namespace toyrenderer
{



}