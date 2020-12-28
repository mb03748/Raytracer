#pragma once
#include "Light.h"
#include "../utilities/Vector3D.hpp"

class DirectionalLight : public Light
{
    public:


        DirectionalLight(Vector3D dir, RGBColor color, float intensity);

        // Copy constructor and assignment operator.
        DirectionalLight(const DirectionalLight &directionallight);
        DirectionalLight &operator=(const DirectionalLight &other);

        //get direction of point light from a point
        virtual Vector3D get_direction(const Point3D &p, const ShadeInfo &sinfo) const;
        virtual RGBColor get_color(const Point3D &p) const;

        //destructor
        virtual ~DirectionalLight() = default;

    protected:
        Vector3D dir;
    private:
};

