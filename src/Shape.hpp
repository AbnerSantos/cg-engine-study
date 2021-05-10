#pragma once

#include "Vector2.hpp"
#include "Color.hpp"
#include <vector>
#include <string>

class Shape
{
    public:
        std::vector<Vector2> vertices;
        Color color;

        ~Shape();
        Vector2 GetPos();
        unsigned int GetPrimitive();

    protected:
        Shape(Vector2 position, Vector2 pivot = Vector2(0.5f, 0.5f));
        Vector2 pos;
        Vector2 pivot;
        unsigned int primitive;
};