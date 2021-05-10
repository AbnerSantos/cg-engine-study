#pragma once

#include "Vector2.hpp"
#include "Shape.hpp"

class Rectangle : public Shape
{
    public:
        Rectangle(Vector2 position, float height, float width, Vector2 pivot = Vector2(0.5f, 0.5f));
};