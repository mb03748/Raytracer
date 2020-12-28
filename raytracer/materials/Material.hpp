#pragma once
#include "../lights/Light.h"
#include "../lights/Ambient.h"
/**
   This file declares the Material class which is an abstract class for concrete
   materials to inherit from.

   Courtesy Kevin Suffern.
*/

class RGBColor;
class ShadeInfo;

class Material {
public:
  // Constructors.
  Material() = default; // does nothing.

  // Copy constuctor and assignment operator.
  Material(const Material &other) = default;
  Material &operator=(const Material &other) = default;

  // Desctructor.
  virtual ~Material() = default;
  virtual RGBColor Color(RGBColor& LightColor) const = 0;
  // Get color.
  virtual RGBColor shade(const ShadeInfo &sinfo, const Light* Light_ptr) const = 0;
  virtual RGBColor shadeAmbient(const ShadeInfo &sinfo, const Ambient* ambient) const = 0;
};
