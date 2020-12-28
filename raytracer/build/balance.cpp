

/**
   This builds a scene that consists of 35 shaded spheres and a plane.
   Perspective viewing is used with a single sample per pixel.
   The spheres are the same as those in the Chapter 14 page one image.

   Courtesy Kevin Suffern.
*/

#include <iostream>
#include "../cameras/Parallel.hpp"
#include "../cameras/Perspective.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"

#include "../materials/BlinnPhong.hpp"
#include "../materials/Matte.h"

#include "../samplers/Simple.hpp"

#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"

#include "../world/World.hpp"
#include "../lights/Light.h"
#include "../lights/Point.h"
#include "../lights/DirectionalLight.h"
#include "../lights/Ambient.h"
#include "../Parser/Happly.h"
#include "../Parser/Ply.h"

#include <iostream>
#include <fstream>
using namespace std;

void
World::build(void) {
    //view plane
  vplane.top_left.x = -3;
  vplane.top_left.y = -3;
  vplane.top_left.z = 0;
  vplane.bottom_right.x = 10;
  vplane.bottom_right.y = 5;
  vplane.bottom_right.z = 0;
  vplane.hres = 50;
  vplane.vres = 50;


  bg_color = black;  // background color.
  this->add_lights(new Point(Point3D(100,100,80), RGBColor(1, 1, 1), 2));
  this->add_lights(new DirectionalLight(Vector3D(-1,-1,1), RGBColor(1, 1, 1), 1));
  this->add_lights(new DirectionalLight(Vector3D(1,1,1), RGBColor(1, 1, 1), 1));

  this->add_lights(new Point(Point3D(-100,100,80), RGBColor(1, 1, 1), 1));
  this->add_lights(new Point(Point3D(-100,100,-80), RGBColor(1, 1, 1), 1));
  this->add_lights(new Point(Point3D(-100,-100,80), RGBColor(1, 1, 1), 2));
  this->add_lights(new DirectionalLight(Vector3D(-100,0,0), RGBColor(1,1,1),5));
  this->add_ambient(new Ambient(1, 1, 1, 1));
   //camera and sampler.
  set_camera(new Parallel(-6, 3, 10));
  sampler_ptr = new Simple(camera_ptr, &vplane);

//   colors
  RGBColor yellow(1, 1, 0);  // yellow
  RGBColor brown(0.71, 0.40, 0.16);  // brown
  RGBColor darkGreen(0.0, 0.41, 0.41);  // darkGreen
  RGBColor orange(1, 0.75, 0);  // orange
  RGBColor green(0, 0.6, 0.3);  // green
  RGBColor lightGreen(0.65, 1, 0.30);  // light green
  RGBColor darkYellow(0.61, 0.61, 0);  // dark yellow
  RGBColor lightPurple(0.65, 0.3, 1);  // light purple
  RGBColor darkPurple(0.5, 0, 1);  // dark purple
  RGBColor grey(0.25);  // grey

  Ply pl("C:/Users/rizwa/OneDrive/Desktop/UNI/CG/parser-ke-saath/p2-p2-terrific-hyenas-main/project/raytracer/big_spider.ply");

  for (int i = 0; i < pl.indi.size(); i++)
  {
      Point3D p1 = pl.vertices[pl.indi[i][0]];

      Point3D p2 = pl.vertices[pl.indi[i][1]];

      Point3D p3 = pl.vertices[pl.indi[i][2]];

      Triangle* triangle_ptr = new Triangle(p1,p2,p3);
      triangle_ptr->set_material(new BlinnPhong(brown));
      add_geometry(triangle_ptr);

  }

}

