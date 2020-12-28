#include "Cosine.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"
#include <iostream>

Cosine::Cosine(): color(0,0,0)   // Default constuctor done
{

}



Cosine::Cosine(float c): color(c,c,c)  // One argument constuctor done
{

}



Cosine::Cosine(float r, float g, float b): color(r,g,b)  // Three argument constuctor done
{

}



Cosine::Cosine(const RGBColor &c)   //Done
{
    color = c;
}



Cosine::Cosine(const Cosine &other)   // Copy constuctor done
{
    color = other.color;
}



Cosine& Cosine::operator=(const Cosine &other)   // assignment operator overloading done
{
    if(this != &other)
    {
        color = other.color;
    }
    return *this;
}

RGBColor Cosine::Color(RGBColor& LightColor) const
{
    return this->color * LightColor;
}


RGBColor Cosine::shade(const ShadeInfo &sinfo, const Light* Light_ptr, const Ambient* ambient) const // taking inner product and multiplying
{
    Vector3D v1 = -Light_ptr->get_direction(sinfo.hit_point, sinfo);
    v1.normalize();
    Vector3D v2 = Vector3D(sinfo.normal);
    v2.normalize();
   // std::cout << v1*v2<<"\n";
    return (std::max(v1 * v2, 0.0)) * Light_ptr->get_color(sinfo.hit_point) + ambient->get_color(sinfo.hit_point);
}
