#pragma once

#include "Vector2.hpp"
#include "Shape.hpp"

class Line : public Shape
{
    public:
        Line(Vector2 pointA, Vector2 pointB, Vector2 pivot);
};