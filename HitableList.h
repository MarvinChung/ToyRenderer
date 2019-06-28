#include "Hitable.h"
namespace toyrenderer{

class HitableList : public Hitable
{
    public:
        HitableList() {}
        HitableList(Hitable **l, int n) {m_list = l ; m_listSize = n;}
        virtual bool isIntersecting(const Ray& ray, float tmin, float tmax, hit_record& rec) const;
        Hitable **m_list;
        int m_listSize;

};

bool HitableList::isIntersecting(const Ray& input_ray, float tmin, float tmax, hit_record& rec) const
{
    hit_record temp_rec;
    bool hit_anything = false;
    Ray ray = input_ray;
    double closest_so_far = tmax;
    for ( int  i = 0; i < m_listSize ; i ++)
    {
        if(m_list[i]->isIntersecting(ray, tmin, closest_so_far, temp_rec))
        {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec=temp_rec;
        }
    }
    return hit_anything;
}

}