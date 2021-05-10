#include "Point.hpp"
#include "GL/glew.h"

Point::Point(Vector2 position) : Shape(position)
{
    vertices.push_back(position);

    this->primitive = GL_POINTS;
}