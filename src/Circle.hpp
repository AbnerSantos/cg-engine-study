#pragma once

#include "Vector2.hpp"
#include "Shape.hpp"

class Circle : public Shape
{
    public:
        Circle(Vector2 pos, float radius, int numOfVertices, Vector2 pivot = Vector2(0.5f, 0.5f));
};