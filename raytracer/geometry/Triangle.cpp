#include "Triangle.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/BBox.hpp"
#include <iostream>
#include <cmath>


Triangle::Triangle(): v0(0,0,0), v1(0,0,0), v2(0,0,0)
{

}



Triangle::Triangle(const Point3D &vert0, const Point3D &vert1, const Point3D &vert2)  // done
{
    v0 = vert0;
    v1 = vert1;
    v2 = vert2;
}



Triangle::Triangle(const Triangle &object) //Copy constructor done
{
    v0 = object.v0;
    v1 = object.v1;
    v2 = object.v2;
}



Triangle& Triangle::operator=(const Triangle &rhs) // assignment operator overloading done
{
    if(this != &rhs)
    {
        v0 = rhs.v0;
        v1 = rhs.v1;
        v2 = rhs.v2;
    }
    return *this;
}

bool Triangle::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
     const float kEpsilon = 0.0000001;
    Point3D vertex0 = this->v0;
    Point3D vertex1 = this->v1;
    Point3D vertex2 = this->v2;

    Vector3D edge1, edge2, h, ss, q;
    float a,f,u,v;
    edge1 = vertex1 - vertex0;
    edge2 = vertex2 - vertex0;
    h = ray.d^edge2;
    a = edge1*h;
    if (a > -kEpsilon && a < kEpsilon)
        return false;    // This ray is parallel to this triangle.
    f = 1.0/a;
    ss = ray.o - vertex0;
    u = f * (ss*h);
    if (u < 0.0 || u > 1.0)
        return false;
    q = ss^edge1;
    v = f * (ray.d*q);
    if (v < 0.0 || u + v > 1.0)
        return false;
    // At this stage we can compute t to find out where the intersection point is on the line.
    float _t = f * (edge2*q);
    if (_t > kEpsilon) // ray intersection
    {
        Point3D p = ray.o + (ray.d * _t);
        t = _t;

        s.hit_point = ray.o + (t * ray.d);
        s.normal = (v1 - v2)^(v1 - v0);

        s.normal.normalize();
        Vector3D v = ray.d;
        v.normalize();
        //std::cout << s.normal * v  << "\t" << s.normal.x << "\t" << s.normal.y << "\t" << s.normal.z << "\n";
        s.ray = ray;
        s.t = t;
        s.hit = true;
        s.material_ptr = this->material_ptr;
        return true;
    }
    else // This means that there is a line intersection but not a ray intersection.
        return false;
}

BBox Triangle::getBBox() const
{
    return BBox();
}

std::string Triangle::to_string() const
{

}
