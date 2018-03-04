//
// Created by Tyler Moses on 3/3/18.
//

#include <shapes.h>   // Shapes Header
#include <cmath>      // M_PI defined to 21 significant digits
#include <iostream>   // Input / Output Stream
/*
 * Shape
 */

Shape::Shape(float x, float y, float z, bool verbose)
{
  if (verbose)
  {
    std::cout << "Shape(" << x << "," << y << "," << z << "," << verbose << ")\n";
  }
  x_ = x;
  y_ = y;
  z_ = z;
  verbose_ = verbose;
}

Shape::~Shape()
{
  if (verbose_)
  {
    std::cout << "~Shape()\n";
  }
}

const char* Shape::Name() const
{
  return "generic";
}

float Shape::Volume() const
{
  return 0.0;
}

float Shape::Area() const
{
  return 0.0;
}

/*
 * Box
 */

Box::Box(float l, float w, float h, bool verbose) : Shape(l, w, h, verbose)
{
  if (verbose)
  {
    std::cout << "Box(" << l << "," << w << "," << h << "," << verbose << ")\n";
  }
}

Box::~Box()
{
  if (verbose_)
  {
    std::cout << "~Box()\n";
  }
}

const char* Box::Name() const
{
  return "box";
}

float Box::Volume() const
{
  return x_ * y_ * z_;
}

float Box::Area() const
{
  return 2 * x_ * y_ + 2 * x_ * z_ + 2 * y_ * z_;
}

/*
 * Cylinder
 */

Cylinder::Cylinder(float r, float h, bool verbose): Shape(r, 0, h, verbose)
{
  if (verbose)
  {
    std::cout << "Cylinder(" << r << "," << h << "," << verbose << ")\n";
  }
}

Cylinder::~Cylinder()
{
  if (verbose_)
  {
    std::cout << "~Cylinder()\n";
  }
}

const char* Cylinder::Name() const
{
  return "cylinder";
}

float Cylinder::Volume() const
{
  return M_PI * x_ * x_ * z_; // pi * r ^ 2 * h
}

float Cylinder::Area() const
{
  // 2 pi r h + 2 pi r ^ 2
  return 2 * M_PI * x_ * z_ + 2 * M_PI * x_ * x_;
}

/*
 * Rectangle
 */

Rectangle::Rectangle(float w, float h, bool verbose): Shape(w, h, 0, verbose)
{
  if (verbose)
  {
    std::cout << "Rectangle(" << w << "," << h << "," << verbose << ")\n";
  }
}

Rectangle::~Rectangle()
{
  if (verbose_)
  {
    std::cout << "~Rectangle()\n";
  }
}

const char* Rectangle::Name() const
{
  return "rectangle";
}

float Rectangle::Area() const
{
  return x_ * y_;
}