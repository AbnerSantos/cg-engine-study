#include "Matrix4x4.hpp"
#include <cassert>
#include <initializer_list>

Matrix4x4::Matrix4x4(const float(&array)[16])
{
    int count = 0;
    for (auto element : array)
    {
        values[count] = element;
        ++count;
    }
}

Matrix4x4::Matrix4x4()
{
    for (int i = 0; i < 16; i++)
        values[i] = 0.0f;
}

Matrix4x4::~Matrix4x4()
{

}

float* Matrix4x4::AsArray()
{
    return values;
}

Matrix4x4 Matrix4x4::operator * (const Matrix4x4& other)
{
    Matrix4x4 temp = zero;

    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 4; j++) 
            for (int k = 0; k < 4; k++) 
                temp[i * 4 + j] += values[i * 4 + k] * other.values[k * 4 + j];

    return temp;
}

float& Matrix4x4::operator[] (int i)
{
    return values[i];
}

Matrix4x4 Matrix4x4::identity = Matrix4x4
({
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
});

Matrix4x4 Matrix4x4::zero = Matrix4x4
({
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f
});