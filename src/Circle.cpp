#include "Circle.hpp"
#include "GL/glew.h"
#include <cmath>

Circle::Circle(Vector2 position, float radius, int numOfVertices, Vector2 pivot) : Shape(position, pivot)
{
    Vector2 temp_pivot = pivot - Vector2(0.5f, 0.5f);
    Vector2 correction = Vector2(-temp_pivot.x * 2 * radius, -temp_pivot.y * 2 * radius);

    float pi = 3.14f;
    float angle = 0.0;

    float x, y;
    for(int i = 0; i < numOfVertices; i++)
    {
	    angle = i * (2.0f*pi)/numOfVertices;
	    x = std::cos(angle)*radius;
	    y = std::sin(angle)*radius;
	    vertices.push_back(Vector2(position.x + x, position.y + y) + correction);
    }

    this->primitive = GL_TRIANGLE_FAN;
}