#include "Simple.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/Ray.hpp"
#include "../cameras/Camera.hpp"
#include "../world/ViewPlane.hpp"
Simple::Simple(Camera *c_ptr, ViewPlane *v_ptr)  // Done
{
    camera_ptr = c_ptr;
    viewplane_ptr = v_ptr;
}



Simple::Simple(const Simple &camera)   //Copy constructor done
{
    camera_ptr = camera.camera_ptr;
    viewplane_ptr = camera.viewplane_ptr;
}



Simple& Simple::operator=(const Simple &other)  // assignment operator overloading done
{
    if(this != &other)
    {
        camera_ptr = other.camera_ptr;
        viewplane_ptr = other.viewplane_ptr;
    }
    return *this;
}


std::vector<Ray> Simple::get_rays(int px, int py) const
{

    double tempx = px;
    double tempy = py;


    double width = viewplane_ptr->bottom_right.x - viewplane_ptr->top_left.x;
    double height = viewplane_ptr->bottom_right.y - viewplane_ptr->top_left.y;
    double pW = width / viewplane_ptr->hres;
    double pH = height / viewplane_ptr->vres;

    Point3D point;
    point.x = pW * tempx + viewplane_ptr->top_left.x;
    point.y = pH * tempy + viewplane_ptr->top_left.y;
    point.z = viewplane_ptr->top_left.z;

    Vector3D dir = camera_ptr->get_direction(point);

    Ray r = Ray(point, dir);
    std::vector<Ray> rayVect = {r};
    return rayVect;

}
