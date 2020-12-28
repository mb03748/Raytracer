#pragma once
#include "Tracer.hpp"
#include "../world/World.hpp"
#include "../materials/Material.hpp"
class BasicTracer : public Tracer {
public:
  // Constructors.
  BasicTracer(World& w);

  // Desctructor.
  virtual ~BasicTracer() = default;

  virtual ShadeInfo hit_objects(const Ray &ray) const override;
  virtual ShadeInfo hit_objects(const Ray &ray, int depth) const override{};
  virtual RGBColor shade(const ShadeInfo& sinfo) const override;
};


