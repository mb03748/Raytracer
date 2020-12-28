#pragma once

#include "Light.h"
#include "../utilities/Vector3D.hpp"

class Ambient : public Light
{
    public:
        Ambient();
                                      // set color to (0, 0, 0).
        Ambient(float c,float intensity);                   // set color to (c, c, c).
        Ambient(float r, float g, float b,float intensity); // set color to (r, g, b).
        Ambient(const RGBColor &c, float intensity);         // set color to c.

        virtual Vector3D get_direction(const Point3D &p, const ShadeInfo &sinfo) const;
        virtual RGBColor get_color(const Point3D &p) const;

         //Copy constuctor and assignment operator.
        virtual ~Ambient() = default;

    protected:

    private:
};

