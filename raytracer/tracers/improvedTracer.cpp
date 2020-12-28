#include "improvedTracer.hpp"
#include <iostream>
improvedTracer::improvedTracer(World& w)
{
    this->w = &w;
}

ShadeInfo improvedTracer::hit_objects(const Ray &ray) const
{
    ShadeInfo s = w->hit_objects(ray);
    s.depth = 20;
    return s;
}


ShadeInfo improvedTracer::hit_objects(const Ray &ray, int depth) const
{
    ShadeInfo s = w->hit_objects(ray);
    s.depth = depth;
    return s;
}


RGBColor improvedTracer::shade(const ShadeInfo& sinfo) const
{
        RGBColor addColor;
        addColor+= sinfo.material_ptr->shadeAmbient(sinfo, w->ambient_ptr);

        for (auto &light: w->lights)
        {
             Ray ShadowRay(sinfo.hit_point, -light->get_direction(sinfo.hit_point,sinfo));
             ShadeInfo shadowinfo = w->hit_objects(ShadowRay);
             if (shadowinfo.hit == false)
             {
                 addColor += sinfo.material_ptr->shade(sinfo, light);
             }

        }
            return sinfo.material_ptr->Color(addColor);

    }




