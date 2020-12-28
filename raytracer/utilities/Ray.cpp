#include "Ray.hpp"



Ray::Ray(): o(0,0,0), d(0,0,0), w(1)    // default constructor done
{

}



Ray::Ray(const Point3D &origin, const Vector3D &dir): o(origin), d(dir), w(1)     // done
{

}



std::string Ray::to_string() const   // yet to be implemented.
{

}