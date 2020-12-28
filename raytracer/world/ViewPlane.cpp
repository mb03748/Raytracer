
#include "ViewPlane.hpp"

ViewPlane::ViewPlane()
{
    this->top_left = Point3D(-320,240,0);
    this->hres = 640;
    this->vres = 480;
    this->bottom_right = Point3D(top_left.x + this->hres,top_left.y - this->vres,0);
}

int ViewPlane:: get_hres() const
{
    return this->hres;
}

void ViewPlane:: set_hres(int h)
{
    this->hres = h;
}

int ViewPlane:: get_vres() const
{
    return this->vres;
}

void ViewPlane:: set_vres(int v)
{
    this->vres = v;
}
