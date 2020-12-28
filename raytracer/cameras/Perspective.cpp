#include "Perspective.hpp"
#include "../utilities/Vector3D.hpp"


Perspective::Perspective(): pos(0,0,0)   // Default constructor done
{

}



Perspective::Perspective(float c): pos(c,c,c)   // One argument constructor done.
{

}



Perspective::Perspective(float x, float y, float z): pos(x,y,z)     // Three argument constructor done.
{

}



Perspective::Perspective(const Point3D &pt)    // Done but not sure if correct.
{
    pos = pt;
}



Perspective::Perspective(const Perspective &camera)   //Copy constructor done
{
    pos = camera.pos;
}



Perspective& Perspective::operator=(const Perspective &other)   // assignment operator overloading done
{
    if(this != &other)
    {
        pos = other.pos;
    }
    return *this;
}

Vector3D Perspective::get_direction(const Point3D &p) const //vec from center
{
    Vector3D vec3= p - this->pos;
    return vec3;
}
