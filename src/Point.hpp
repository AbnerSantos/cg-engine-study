#pragma once

#include "Vector2.hpp"
#include "Shape.hpp"

class Point : public Shape
{
    public:
        Point(Vector2 position);
};