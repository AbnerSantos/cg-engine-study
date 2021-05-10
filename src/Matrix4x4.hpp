#pragma once

class Matrix4x4
{
    public:
        Matrix4x4();
        Matrix4x4(const float(&array)[16]);
        ~Matrix4x4();
        float* AsArray();
        Matrix4x4 operator * (const Matrix4x4& other);
        float& operator[](int i);

        static Matrix4x4 identity;
        static Matrix4x4 zero;
    
    private:
        float values[16];
};