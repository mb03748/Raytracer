#include "Point.h"


Point::Point(Point3D pos, RGBColor color, float intensity)
{
    this->color = color;
    this->pos = pos;
    this->intensity = intensity;
}

Point::Point(const Point &point)
{
    this->color = point.color;
    this->pos = point.pos;
    this->intensity = point.intensity;
}

Point& Point::operator=(const Point &other)
{
    this->color = other.color;
    this->pos = other.pos;
    this->intensity = other.intensity;
    return *this;
}

Vector3D Point::get_direction(const Point3D &p, const ShadeInfo &sinfo) const
{
    return (p - this->pos);
}

RGBColor Point::get_color(const Point3D &p) const
{
    return (this->color * this->intensity);
}
