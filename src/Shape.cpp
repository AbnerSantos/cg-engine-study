#include "Shape.hpp"
#include <cmath>
#include <iostream>

Shape::Shape(Vector2 position, Vector2 pivot) : pos(position), vertices(), color(1.0f, 0.0f, 0.0f, 1.0f), pivot(pivot)
{
    
}

Vector2 Shape::GetPos()
{
    return this->pos;
}

unsigned int Shape::GetPrimitive()
{
    return this->primitive;
}

Shape::~Shape()
{

}