#include "Plane.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/BBox.hpp"
Plane::Plane()
{
    a = Point3D(0,0,0);
    n = Vector3D(0,-1,0);
    n.normalize();
}

Plane::Plane(const Point3D &pt,const Vector3D &n): a(pt), n(n)
{
    this-> n.normalize();
}

Plane::Plane(const Plane &object)  // copy constructor done.
{
    a = object.a;
    n = object.n;
}

Plane& Plane::operator=(const Plane &rhs)   // assignment operator overloading done, seems correct.
{
    if(this != &rhs)
    {
        a = rhs.a;
        n = rhs.n;
    }
     return *this;
}

bool Plane::hit(const Ray &ray, float &t, ShadeInfo &s) const //point of intersection - a . normal = 0
{
    double t2 = ((this->a - ray.o) * this->n) / ((ray.d) * this->n); //solve equation to get t

    if (t2 < kEpsilon)
    {
        return false;
    }

    t = t2;

    s.hit = true;
    s.material_ptr = this->material_ptr;
    s.normal = this->n;
    s.ray = ray;
    s.t = t;
    s.hit_point = ray.o + ray.d * t;
    return true;
}

BBox Plane::getBBox() const
{
    return BBox();
}

std::string Plane::to_string() const
{

}
