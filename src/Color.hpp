#pragma once

class Color
{
    public:
        static Color red;
        static Color green;
        static Color blue;
        static Color yellow;
        static Color orange;
        static Color cyan;
        static Color white;
        static Color black;
        static Color magenta;
        static Color purple;
        static Color clear;

        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
        float a = 0.0f;

        Color(float r, float g, float b, float a);
        Color(int r, int g, int b, int a);
        ~Color();
        static Color Random();
};