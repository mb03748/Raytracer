#include "Ambient.h"


Ambient::Ambient()  // Default constuctor done
{
    this->color = RGBColor(1,1,1);
    this->intensity = 1;
}



Ambient::Ambient(float c, float intensity) // One argument constuctor done
{
    this->color = RGBColor(c,c,c);
    this->intensity = intensity;
}



Ambient::Ambient(float r, float g, float b, float intensity)  // Three argument constuctor done
{
    this->color = RGBColor(r,g,b);
    this->intensity = intensity;

}

Vector3D Ambient::get_direction(const Point3D &p, const ShadeInfo &sinfo) const
{
    return Vector3D(-sinfo.normal);
}

RGBColor Ambient::get_color(const Point3D &p) const
{
    return (this->color * this->intensity);
}




Ambient::Ambient(const RGBColor &c, float intensity)   //Done
{
    this->color = c;
    this->intensity = intensity;
}
