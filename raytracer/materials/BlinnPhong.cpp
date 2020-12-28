#include "BlinnPhong.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"
#include <iostream>
#include <math.h>
BlinnPhong::BlinnPhong(): color(0,0,0)   // Default constuctor done
{

}



BlinnPhong::BlinnPhong(float c, int s): color(c,c,c), shine(s)  // One argument constuctor done
{

}

BlinnPhong::BlinnPhong(float c): color(c,c,c){}


BlinnPhong::BlinnPhong(float r, float g, float b, int s): color(r,g,b), shine(s)  // Three argument constuctor done
{

}



BlinnPhong::BlinnPhong(const RGBColor &c, int s): shine(s)   //Done
{
    color = c;
}

BlinnPhong::BlinnPhong(const RGBColor &c)   //Done
{
    color = c;
}

BlinnPhong::BlinnPhong(const BlinnPhong &other)   // Copy constuctor done
{
    color = other.color;
    shine = other.shine;
}



BlinnPhong& BlinnPhong::operator=(const BlinnPhong &other)   // assignment operator overloading done
{
    if(this != &other)
    {
        color = other.color;
        shine = other.shine;
    }
    return *this;
}

RGBColor BlinnPhong::Color(RGBColor& LightColor) const
{
    return this->color * LightColor;
}


RGBColor BlinnPhong::shade(const ShadeInfo &sinfo, const Light* Light_ptr) const // taking inner product and multiplying
{
    Vector3D v1 = -Light_ptr->get_direction(sinfo.hit_point, sinfo);
    v1.normalize();
    Vector3D v2 = Vector3D(sinfo.normal);
    v2.normalize();
   // std::cout << v1*v2<<"\n";
    Vector3D v3 = -sinfo.ray.d;
    v3.normalize();
    Vector3D H = Vector3D(v3 + v1);
    H.normalize();
    double specAng = std::max((H * v2), 0.0);
    double spec = pow(specAng, shine);
    return (std::max(v1 * v2, 0.0) + spec) * Light_ptr->get_color(sinfo.hit_point);
}


RGBColor BlinnPhong::shadeAmbient(const ShadeInfo &sinfo,const Ambient* ambient) const // taking inner product and multiplying
{
    return ambient->get_color(sinfo.hit_point);
//    Vector3D v1 = -Light_ptr->get_direction(sinfo.hit_point, sinfo);
//    v1.normalize();
//    Vector3D v2 = Vector3D(sinfo.normal);
//    v2.normalize();
//   // std::cout << v1*v2<<"\n";
//    Vector3D v3 = -sinfo.ray.d;
//    v3.normalize();
//    Vector3D H = Vector3D(v3 + v1);
//    H.normalize();
//    double specAng = std::max((H * v2), 0.0);
//    double spec = pow(specAng, shine);
//    return (std::max(v1 * v2, 0.0) + spec) * Light_ptr->get_color(sinfo.hit_point) + ambient->get_color(sinfo.hit_point);
}
