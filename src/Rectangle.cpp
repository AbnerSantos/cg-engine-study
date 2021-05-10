#include "Rectangle.hpp"
#include "GL/glew.h"

Rectangle::Rectangle(Vector2 position, float height, float width, Vector2 pivot) : Shape(position, pivot)
{
    Vector2 correction = Vector2(-pivot.x * width, -pivot.y * height);

    vertices.push_back(Vector2(position.x, position.y + height) + correction);
    vertices.push_back(Vector2(position.x + width, position.y + height) + correction);
    vertices.push_back(position + correction);
    vertices.push_back(Vector2(position.x + width, position.y) + correction);

    this->primitive = GL_TRIANGLE_STRIP;
}