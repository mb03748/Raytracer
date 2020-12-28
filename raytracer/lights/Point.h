
#pragma once
#include "Light.h"
#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"


class Point : public Light
{

    public:
        //constructor
        Point(Point3D pos, RGBColor color, float intensity);

        // Copy constructor and assignment operator.
        Point(const Point &point);
        Point &operator=(const Point &other);

        //get direction of point light from a point
        virtual Vector3D get_direction(const Point3D &p, const ShadeInfo &sinfo) const;
        virtual RGBColor get_color(const Point3D &p) const;

        //destructor
        virtual ~Point() = default;

    protected:
        Point3D pos;


    private:
};

