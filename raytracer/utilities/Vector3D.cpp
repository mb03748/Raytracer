#include "Vector3D.hpp"
#include "Point3D.hpp"
#include <cmath>

Vector3D::Vector3D(): x(0), y(0), z(0)
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}



Vector3D::Vector3D(double c): x(c), y(c), z(c)
{
    this->x = c;
    this->y = c;
    this->z = c;

}



Vector3D::Vector3D(double _x, double _y, double _z): x(_x), y(_y), z(_z)
{
    this->x = _x;
    this->y = _y;
    this->z = _z;
}



Vector3D::Vector3D(const Point3D &p)     // done.
{
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}


Vector3D& Vector3D::operator=(const Point3D &rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
}



std::string Vector3D::to_string() const    // To be implemented.
{

}



Vector3D Vector3D::operator-() const
{
    return Vector3D(-(this->x), -(this->y), -(this->z));
}



Vector3D Vector3D::operator+(const Vector3D &v) const
{
    return Vector3D((this->x + v.x), (this->y + v.y), (this->z + v.z));
}



Vector3D& Vector3D::operator+=(const Vector3D &v)
{
    this->x = this->x + v.x;
    this->y = this->y + v.y;
    this->z = this->z + v.z;

    return *(this);
}



Vector3D Vector3D::operator-(const Vector3D &v) const
{
    return Vector3D((this->x - v.x), (this->y - v.y), (this->z - v.z));
}



Vector3D Vector3D::operator-=(const Vector3D &v) const
{
    double px, py, pz;

    px = this->x - v.x;
    py = this->y - v.y;
    pz = this->z - v.z;

    //return *(this);

    return Vector3D(px,py,pz);

}



Vector3D Vector3D::operator*(const double a) const
{
    return Vector3D((this->x * a), (this->y * a), (this->z * a));
}



Vector3D Vector3D::operator/(const double a) const
{
    return Vector3D((this->x / a), (this->y / a), (this->z / a));
}



double Vector3D::length() const
{
    return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}



double Vector3D::len_squared() const
{
    double temp = this->length();
    return (temp * temp);
}



void Vector3D::normalize()
{
    double mag = this->length();

    this->x = this->x / mag;
    this->y = this->y / mag;
    this->z = this->z / mag;
}



double Vector3D::operator*(const Vector3D &b) const
{
    return ((this->x * b.x) + (this->y * b.y) + (this->z * b.z));
}



Vector3D Vector3D::operator^(const Vector3D &v) const
{
    double px, py, pz;

    px = (y * v.z) - (z * v.y);
    py = (z * v.x) - (x * v.z);
    pz = (x * v.y) - (y * v.x);

    return Vector3D(px,py,pz);

}



Vector3D operator*(const double a, const Vector3D &v)
{
    return Vector3D((v.x * a), (v.y * a), (v.z * a));
}

