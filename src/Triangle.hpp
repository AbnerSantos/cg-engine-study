#pragma once

#include "Vector2.hpp"
#include "Shape.hpp"

class Triangle : public Shape
{
    public:
        enum Type { Isosceles, Right };
        Triangle(Vector2 position, float height, float width, Type type, Vector2 pivot);
};