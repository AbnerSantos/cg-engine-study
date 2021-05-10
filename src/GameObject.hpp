#pragma once

#include "Matrix4x4.hpp"
#include "Vector2.hpp"
#include "Shape.hpp"
#include <vector>

class GameObject
{
    public:
        Vector2 position;
        float rotation;
        Vector2 scale;

        GameObject(Vector2 position = Vector2::zero);
        ~GameObject();
        std::vector<Shape> GetShapes();
        void AddShape(Shape shape);
        Matrix4x4 GetTransformMatrix();
        std::vector<Vector2> GetVertices();

    private:
        Matrix4x4 posMat;
        Matrix4x4 rotMat;
        Matrix4x4 scaMat;

        std::vector<Shape> shapes;
};