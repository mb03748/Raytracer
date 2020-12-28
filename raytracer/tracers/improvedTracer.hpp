#pragma once
#include "Tracer.hpp"
#include "../world/World.hpp"
#include "../materials/Material.hpp"

class improvedTracer : public Tracer {
public:
  // Constructors.
  improvedTracer(World& w);

  // Desctructor.
  virtual ~improvedTracer() = default;

  virtual ShadeInfo hit_objects(const Ray &ray) const override;

  virtual RGBColor shade(const ShadeInfo& sinfo) const override;

  ShadeInfo hit_objects(const Ray &ray, int depth) const;

};


