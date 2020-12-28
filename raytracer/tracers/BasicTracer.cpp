#include "BasicTracer.hpp"

BasicTracer::BasicTracer(World& w)
{
    this->w = &w;
}

ShadeInfo BasicTracer::hit_objects(const Ray &ray) const
{
    return w->hit_objects(ray);
}

RGBColor BasicTracer::shade(const ShadeInfo& sinfo) const
{
    RGBColor addColor;
    for (const auto &lightSrc: w->lights)
    {
        addColor += sinfo.material_ptr->shade(sinfo, lightSrc);
    }
    return sinfo.material_ptr->Color(addColor);
}
