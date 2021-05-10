#include "Color.hpp"
#include <cstdlib>
#include <ctime>

Color::Color(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Color::Color(int r, int g, int b, int a)
{
    this->r = 255.0f/r;
    this->g = 255.0f/g;
    this->b = 255.0f/b;
    this->a = 255.0f/a;
}

Color::~Color()
{

}

Color Color::red = Color(1.0f, 0.0f, 0.0f, 1.0f);
Color Color::green = Color(0.0f, 1.0f, 0.0f, 1.0f);
Color Color::blue = Color(0.0f, 0.0f, 1.0f, 1.0f);
Color Color::yellow = Color(1.0f, 1.0f, 0.0f, 1.0f);
Color Color::orange = Color(1.0f, 0.5f, 0.0f, 1.0f);
Color Color::cyan = Color(0.0f, 1.0f, 1.0f, 1.0f);
Color Color::white = Color(1.0f, 1.0f, 1.0f, 1.0f);
Color Color::black = Color(0.0f, 0.0f, 0.0f, 1.0f);
Color Color::purple = Color(0.5f, 0.0f, 1.0f, 1.0f);
Color Color::magenta = Color(1.0f, 0.0f, 1.0f, 1.0f);
Color Color::clear = Color(0.0f, 0.0f, 0.0f, 0.0f);

Color Color::Random()
{
    return Color
    (
        static_cast <float> (rand()) / static_cast <float> (RAND_MAX),
        static_cast <float> (rand()) / static_cast <float> (RAND_MAX),
        static_cast <float> (rand()) / static_cast <float> (RAND_MAX),
        1.0f
    );
}