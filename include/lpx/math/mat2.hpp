#pragma once

#include "lpx/math/vec2.hpp"

namespace lpx {

struct Mat2 { 
    Vec2 col1, col2; 

    Mat2& operator+=(Mat2 other);
    Mat2& operator-=(Mat2 other);

    Mat2& operator*=(float k);
    Mat2& operator/=(float k);

    float Determinant() const;

    Mat2 Inverse() const;
    void Invert();
};

bool operator==(Mat2 lhs, Mat2 rhs);
bool operator!=(Mat2 lhs, Mat2 rhs);

Mat2 operator+(Mat2 lhs, Mat2 rhs);
Mat2 operator-(Mat2 lhs, Mat2 rhs);

Mat2 operator*(Mat2 mat, float k);
Mat2 operator*(float k, Mat2 mat);
Mat2 operator/(Mat2 mat, float k);

Mat2 operator*(Mat2 lhs, Mat2 rhs);
Vec2 operator*(Mat2 mat, Vec2 vec);

} // namespace lpx