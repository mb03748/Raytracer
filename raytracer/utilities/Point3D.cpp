#include "Point3D.hpp"
#include "Vector3D.hpp"
#include <cmath>


Point3D::Point3D():x(0), y(0), z(0)
{

}



Point3D::Point3D(float c): x(c), y(c), z(c)
{

}



Point3D::Point3D(float x, float y, float z): x(x), y(y), z(z)
{

}



Point3D Point3D::operator-() const
{
      return Point3D(-(this->x), -(this->y), -(this->z));
}



Vector3D Point3D::operator-(const Point3D &p) const
{
  return Vector3D((x - p.x), (y - p.y), (z - p.z));
}



Point3D Point3D::operator+(const Vector3D &v) const
{
  return Point3D((x + v.x), (y + v.y), (z + v.z));
}



Point3D Point3D::operator-(const Vector3D &v) const
{
  return Point3D((x - v.x), (y - v.y), (z - v.z));
}



Point3D Point3D::operator*(const float s) const
{
  return Point3D((x * s), (y * s), (z * s));
}



float Point3D::distance(const Point3D &p) const
{
  float temp = ((p.x - x) * (p.x - x)) + ((p.y - y) * (p.y - y)) + ((p.z - z) * (p.z - z));
  float out = sqrt(temp);
  return out;
}



float Point3D::d_squared(const Point3D &p) const
{
  float temp = distance(p);
  float out = temp * temp;
  return out;
}



Point3D operator*(const float a, const Point3D &pt)
{
  return Point3D((pt.x * a), (pt.y * a), (pt.z * a));
}



Point3D min(const Point3D& a, const Point3D& b)         // done
{
  float px, py, pz;

  if (a.x < b.x)
  {
    px = a.x;
  }
  else
  {
    px = b.x;
  }

  if (a.y < b.y)
  {
    py = a.y;
  }
  else
  {
    py = b.y;
  }

  if (a.z < b.z)
  {
    pz = a.z;
  }
  else
  {
    pz = b.z;
  }

  return Point3D(px, py, pz);

}



Point3D max(const Point3D& a, const Point3D& b)        //done
{
  float px, py, pz;

  if (a.x > b.x)
  {
    px = a.x;
  }
  else
  {
    px = b.x;
  }

  if (a.y > b.y)
  {
    py = a.y;
  }
  else
  {
    py = b.y;
  }

  if (a.z > b.z)
  {
    pz = a.z;
  }
  else
  {
    pz = b.z;
  }

  return Point3D(px, py, pz);
}
