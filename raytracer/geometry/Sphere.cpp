#include "Sphere.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/BBox.hpp"
#include "../utilities/Constants.hpp"
#include <cmath>
#include <iostream>
Sphere::Sphere():c(0,0,0), r(0)      // default constructor done
{

}

Sphere::Sphere(const Point3D &center, float radius): c(center), r(radius)   // done
{

}



Sphere::Sphere(const Sphere &object)  //Copy constructor done
{
    c = object.c;
    r = object.r;
}


Sphere& Sphere::operator=(const Sphere &rhs)   // assignment operator overloading done
{
    if(this != &rhs)
    {
        c = rhs.c;
        r = rhs.r;
    }
     return *this;
}

bool Sphere::hit(const Ray &ray, float &t, ShadeInfo &s) const //point of intersection - center . itself = r^2
{
    double c = (ray.o - this->c)*(ray.o - this->c) - (this->r * this->r);
    double b = 2 * (ray.o - this->c)*(ray.d);
    double a = (ray.d*ray.d);

    if (b*b - 4*a*c < 0) //checking determinant
    {
        return false;
    }

    else if (b*b - 4*a*c == 0)
    {
        float t0 = -b/(2*a);
        if (t0 < kEpsilon)
        {

            return false;
        }
        t = t0;
    }
    else if (b*b - 4*a*c > 0)
    {
        float t0 = (-b - sqrt(b*b - 4*a*c))/(2*a);
        float t1 = (-b + sqrt(b*b - 4*a*c))/(2*a);

        if (t1 < kEpsilon && t0 < kEpsilon)
        {
           return false;;
        }
        else if (t1 > kEpsilon && t0 < kEpsilon)
        {
            t = t1;
        }
        else if (t1 > kEpsilon && t0 > kEpsilon)
        {
            t = t0;
        }

    }



    s.hit = true;
    s.material_ptr = this->material_ptr;
    s.hit_point = ray.o + ray.d * t;

    s.normal = s.hit_point - this->c;
    s.normal.normalize();

    s.ray = ray;
    s.t = t;

    return true;
}


BBox Sphere::getBBox() const
{
    return BBox();
}

std::string Sphere::to_string() const
{

}
