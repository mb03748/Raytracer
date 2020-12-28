#include "BBox.hpp"



BBox::BBox(const Point3D& min, const Point3D& max): pmin(min), pmax(max)
{

}



bool BBox::contains(const Point3D& p)
{
    bool contain = false;

    if ((p.x <= pmax.x) && (p.y <= pmax.y) && (p.z <= pmax.z))
    {
        if ((p.x >= pmin.x) && (p.y >= pmin.y) && (p.z >= pmin.z))
        {
            contain = true;
        }
    }

    return contain;
}
