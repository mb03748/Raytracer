

#include "Material.hpp"
#include <algorithm>
#include "../utilities/RGBColor.hpp"
#include "../lights/Light.h"

class Matte : public Material {
protected:
  RGBColor color; // the color of the material.

public:
  // Constructors.
  Matte();                          // set color to (0, 0, 0).
  Matte(float c);                   // set color to (c, c, c).
  Matte(float r, float g, float b); // set color to (r, g, b).
  Matte(const RGBColor &c);         // set color to c.

  // Copy constuctor and assignment operator.
  Matte(const Matte &other);
  Matte &operator=(const Matte &other);
  virtual RGBColor Color(RGBColor& LightColor) const;
  // Desctructor.
  virtual ~Matte() = default;

  /* Returned shade is: color * cos \theta.
     \theta is the angle between the normal at the hit pont and the ray.
     Assuming unit vectors, cos \theta = dot product of normal and -ray.dir.
  */
  virtual RGBColor shade(const ShadeInfo &sinfo, const Light* Light_ptr) const;
  virtual RGBColor shadeAmbient(const ShadeInfo &sinfo, const Ambient* ambient) const;
};

