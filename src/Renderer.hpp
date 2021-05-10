#pragma once

#include "GameObject.hpp"

class Renderer
{
    public:
        Renderer(int colorLoc, int transformLoc);
        ~Renderer();

        int Draw(GameObject gameObject, int startIndex = 0);
        int Draw(Shape shape, int startIndex = 0);

        int colorLoc;
        int transformLoc;
};