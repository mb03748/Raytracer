#pragma once

/**
   This file declares the BlinnPhong class which represents a simple BlinnPhong
   material.

   It assigns a shade according to the BlinnPhong of the angle between the incoming
   ray direction and the normal at the hit point.

   Courtesy Kevin Suffern.
*/

#include "Material.hpp"
#include <algorithm>
#include "../utilities/RGBColor.hpp"
#include "../lights/Light.h"
class BlinnPhong : public Material {
protected:
  RGBColor color; // the color of the material.
  int shine = 32;

public:
  // Constructors.
  BlinnPhong();                          // set color to (0, 0, 0).
  BlinnPhong(float c, int s);                   // set color to (c, c, c).
  BlinnPhong(float r, float g, float b, int s); // set color to (r, g, b).
  BlinnPhong(const RGBColor &c, int s);         // set color to c.
  BlinnPhong(float c);
  BlinnPhong(const RGBColor &c);
  // Copy constuctor and assignment operator.
  BlinnPhong(const BlinnPhong &other);
  BlinnPhong &operator=(const BlinnPhong &other);
  virtual RGBColor Color(RGBColor& LightColor) const;
  // Desctructor.
  virtual ~BlinnPhong() = default;

  /* Returned shade is: color * cos \theta.
     \theta is the angle between the normal at the hit pont and the ray.
     Assuming unit vectors, cos \theta = dot product of normal and -ray.dir.
  */
  virtual RGBColor shade(const ShadeInfo &sinfo, const Light* Light_ptr) const;
  virtual RGBColor shadeAmbient(const ShadeInfo &sinfo,const Ambient* ambient) const;
};
