#include "Triangle.hpp"
#include "GL/glew.h"

Triangle::Triangle(Vector2 position, float height, float width, Type type, Vector2 pivot) : Shape(position, pivot)
{
    Vector2 correction = Vector2(-pivot.x * width, -pivot.y * height);

    if(type == Isosceles)
    {
        vertices.push_back(Vector2(position.x + width/2, position.y + height) + correction);
        vertices.push_back(position + correction);
        vertices.push_back(Vector2(position.x + width, position.y) + correction);
    }
    else if(type == Right)
    {
        vertices.push_back(Vector2(position.x, position.y + height) + correction);
        vertices.push_back(position + correction);
        vertices.push_back(Vector2(position.x + width, position.y) + correction);
    }

    this->primitive = GL_TRIANGLES;
}