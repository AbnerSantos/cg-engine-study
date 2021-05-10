#pragma once

class Vector2
{
    public:
        float x;
        float y;

        static Vector2 zero;
        static Vector2 up;
        static Vector2 down;
        static Vector2 right;
        static Vector2 left;

        Vector2(float x, float y);
        ~Vector2();
        void Set(float x, float y);
        Vector2 operator + (const Vector2& obj);
        Vector2 operator - (const Vector2& obj);
        Vector2 operator * (const float mult);
        Vector2 operator / (const float div);
};