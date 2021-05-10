#include "GameObject.hpp"
#include <cmath>

GameObject::GameObject(Vector2 position) :
    position(position),
    rotation(0.0f),
    scale(Vector2(1.0f, 1.0f)),
    posMat(Matrix4x4::identity),
    rotMat(Matrix4x4::identity),
    scaMat(Matrix4x4::identity),
    shapes()
{
    
}

std::vector<Shape> GameObject::GetShapes()
{
    return this->shapes;
}

void GameObject::AddShape(Shape shape)
{
    this->shapes.push_back(shape);
}

Matrix4x4 GameObject::GetTransformMatrix()
{
    this->posMat = Matrix4x4
    ({
        1.0f, 0.0f, 0.0f, position.x,
        0.0f, 1.0f, 0.0f, position.y,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    });

    float pi = 3.1415;
    float radians = rotation * (pi / 180.0f);

    this->rotMat = Matrix4x4
    ({
        std::cos(radians), -std::sin(radians), 0.0f, 0.0f,
        std::sin(radians), std::cos(radians), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    });

    this->scaMat = Matrix4x4
    ({
        scale.x, 0.0f, 0.0f, 0.0f,
        0.0f, scale.y, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    });

    return posMat * rotMat * scaMat;
}

std::vector<Vector2> GameObject::GetVertices()
{
    std::vector<Vector2> v;
    for (auto shape : shapes)
        v.insert(v.end(), shape.vertices.begin(), shape.vertices.end());
    return v;
}

GameObject::~GameObject()
{
    
}