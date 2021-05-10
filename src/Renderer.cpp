#include "Renderer.hpp"
#include <GL/glew.h>  

int Renderer::Draw(GameObject gameObject, int startIndex)
{
    int index = startIndex;

    for(auto shape : gameObject.GetShapes())
    {
        glUniformMatrix4fv(transformLoc, 1, GL_TRUE, gameObject.GetTransformMatrix().AsArray());
        index = Draw(shape, index);
    }

    return index;
}

int Renderer::Draw(Shape shape, int startIndex)
{
    glUniform4f(colorLoc, shape.color.r, shape.color.g, shape.color.b, shape.color.a);
    glDrawArrays(shape.GetPrimitive(), startIndex, shape.vertices.size());
    return startIndex + shape.vertices.size();
}

Renderer::Renderer(int colorLoc, int transformLoc)
{
    this->colorLoc = colorLoc;
    this->transformLoc = transformLoc;
}
        
Renderer::~Renderer()
{

}