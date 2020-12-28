#include "Parallel.hpp"



Parallel::Parallel(): dir(0,0,-1)   // Default constructor done, not sure if correct.
{

}



Parallel::Parallel(float c): dir(c,c,c)  // One argument constructor done.
{

}


Parallel::Parallel(float x, float y, float z): dir(x,y,z)    // Three argument constructor done.
{

}



Parallel::Parallel(const Vector3D &d)  // done
{
    dir = d;
}



Parallel::Parallel(const Parallel &camera)   //Copy constructor done
{
    dir = camera.dir;
}



Parallel& Parallel::operator=(const Parallel &other)    // assignment operator overloading done
{
    if(this != &other)
    {
        dir = other.dir;
    }
     return *this;
}

Vector3D Parallel::get_direction(const Point3D &p) const
{
    return dir;
}
