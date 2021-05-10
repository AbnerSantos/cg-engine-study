#include "Line.hpp"
#include "GL/glew.h"
#include <cmath>

Line::Line(Vector2 pointA, Vector2 pointB, Vector2 pivot) : Shape(pointA, pivot)
{
    float height = std::fabs(pointB.y - pointA.y);
    float width = std::fabs(pointB.x - pointA.x);

    Vector2 correction = Vector2(-pivot.x * width, -pivot.y * height);

    vertices.push_back(pointA + correction);
    vertices.push_back(pointB + correction);

    this->primitive = GL_LINES;
}