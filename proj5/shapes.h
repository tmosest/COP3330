//
// Created by Tyler Moses on 3/3/18.
//

#ifndef SHAPES_H
#define SHAPES_H

class Shape {
public:
    Shape(float x = 1, float y = 1, float z = 1, bool verbose = false);
    virtual ~Shape();
    virtual const char* Name() const;
    virtual float Volume() const;
    virtual float Area()  const;
protected:
    float x_, y_, z_; // dimensions of the shape
    bool verbose_;    // default value 0, given in constructor prototype
};

class Box: public Shape {
public:
    Box(float l = 1, float w = 1, float h = 1, bool verbose = false);
    virtual ~Box();
    const char* Name() const;
    float Volume() const;
    float Area() const;
};

class Cylinder: public Shape {
public:
    Cylinder(float r = 1, float h = 1, bool verbose = false);
    virtual ~Cylinder();
    const char* Name() const;
    float Volume() const;
    float Area() const;
};

class Rectangle: public Shape {
public:
    Rectangle(float w = 1, float h = 1, bool verbose = false);
    virtual ~Rectangle();
    const char* Name() const;
    float Area() const;
};

#endif // SHAPES_H
