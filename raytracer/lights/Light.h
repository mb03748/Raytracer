
#pragma once
#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"
class Point3D;
class Vector3D;

class Light
{
    public:
        Light() = default;

        Light(const Light &other) = default;
        Light &operator=(const Light &other) = default;

        virtual Vector3D get_direction(const Point3D &p, const ShadeInfo &sinfo) const = 0;
        virtual RGBColor get_color(const Point3D &p) const = 0;

        // Desctructor.
        virtual ~Light() = default;

    protected:
        RGBColor color;
        float intensity;

    private:
};

