#include "World.hpp"
#include "../cameras/Camera.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../geometry/Geometry.hpp"
#include "../utilities/Constants.hpp"

World::World()
{
    this->camera_ptr = nullptr;
    this->sampler_ptr = nullptr;
}

World::~World()
{
    delete camera_ptr;
    delete sampler_ptr;
}

void World::add_geometry(Geometry *geom_ptr)
{
    this->geometry.push_back(geom_ptr);
}

void World::set_camera(Camera *c_ptr)
{
    this->camera_ptr = c_ptr;
}

void World::add_ambient(Ambient *al_ptr)
{
    this->ambient_ptr = al_ptr;
}

void World::add_lights(Light* light_ptr)
{
    this->lights.push_back(light_ptr);
}

ShadeInfo World::hit_objects(const Ray &ray)
{
    float t = kHugeValue;
    ShadeInfo sinfo(*this);
    for (int i = 0; i < geometry.size(); i++)
    {
        float currt;
        ShadeInfo currSinfo(*this);
        if (geometry[i]->hit(ray, currt, currSinfo))
        {
            if (currt < t)
            {
                t = currt;
                sinfo = currSinfo;
            }
        }
    }
    return sinfo;
}
