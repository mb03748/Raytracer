#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(Vector3D dir, RGBColor color, float intensity)
{
    this->color = color;
    this->dir = dir;
    this->intensity = intensity;
}

DirectionalLight::DirectionalLight(const DirectionalLight &directionallight)
{
    this->color = directionallight.color;
    this->dir = directionallight.dir;
    this->intensity = directionallight.intensity;
}

DirectionalLight& DirectionalLight::operator=(const DirectionalLight &other)
{
    this->color = other.color;
    this->dir = other.dir;
    this->intensity = other.intensity;
    return *this;
}

Vector3D DirectionalLight::get_direction(const Point3D &p, const ShadeInfo &sinfo) const
{
    return this->dir;
}

RGBColor DirectionalLight::get_color(const Point3D &p) const
{
    return this->color * this->intensity;
}
