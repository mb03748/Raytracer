
#include "Matte.h"
#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"
#include <iostream>
#include <math.h>
Matte::Matte(): color(0,0,0)   // Default constuctor done
{

}



Matte::Matte(float c): color(c,c,c)  // One argument constuctor done
{

}



Matte::Matte(float r, float g, float b): color(r,g,b)  // Three argument constuctor done
{

}



Matte::Matte(const RGBColor &c)   //Done
{
    color = c;
}



Matte::Matte(const Matte &other)   // Copy constuctor done
{
    color = other.color;
}



Matte& Matte::operator=(const Matte &other)   // assignment operator overloading done
{
    if(this != &other)
    {
        color = other.color;
    }
    return *this;
}

RGBColor Matte::Color(RGBColor& LightColor) const
{
    return this->color * LightColor;
}


RGBColor Matte::shade(const ShadeInfo &sinfo, const Light* Light_ptr) const // taking inner product and multiplying
{
    Vector3D v1 = -Light_ptr->get_direction(sinfo.hit_point, sinfo);
    v1.normalize();
    Vector3D v2 = Vector3D(sinfo.normal);
    v2.normalize();
   // std::cout << v1*v2<<"\n";
    return std::max(v1 * v2, 0.0) * Light_ptr->get_color(sinfo.hit_point);
}

RGBColor Matte::shadeAmbient(const ShadeInfo &sinfo, const Ambient* ambient) const // taking inner product and multiplying
{
    return ambient->get_color(sinfo.hit_point);
//    Vector3D v1 = -Light_ptr->get_direction(sinfo.hit_point, sinfo);
//    v1.normalize();
//    Vector3D v2 = Vector3D(sinfo.normal);
//    v2.normalize();
//   // std::cout << v1*v2<<"\n";
//    return std::max(v1 * v2, 0.0) * Light_ptr->get_color(sinfo.hit_point) + ambient->get_color(sinfo.hit_point);
}
