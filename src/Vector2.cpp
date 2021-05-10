#include "Vector2.hpp"

Vector2::Vector2(float x, float y)
{
    Set(x, y);
}

void Vector2::Set(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2 Vector2::operator + (const Vector2& obj)
{
    return Vector2(x + obj.x, y + obj.y);
}

Vector2 Vector2::operator - (const Vector2& obj)
{
    return Vector2(x - obj.x, y - obj.y);
}

Vector2 Vector2::operator * (const float mult)
{
    return Vector2(x * mult, y * mult);
}

Vector2 Vector2::operator / (const float div)
{
    return Vector2(x / div, y / div);
}

Vector2 Vector2::zero = Vector2(0.0f, 0.0f);
Vector2 Vector2::up = Vector2(0.0f, 1.0f);
Vector2 Vector2::down = Vector2(0.0f, -1.0f);
Vector2 Vector2::left = Vector2(-1.0f, 0.0f);
Vector2 Vector2::right = Vector2(1.0f, 0.0f);

Vector2::~Vector2()
{

}