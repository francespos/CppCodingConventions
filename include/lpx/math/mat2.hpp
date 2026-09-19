#pragma once

#include "lpx/math/vec2.hpp"

namespace lpx {

struct Mat2 { 
    Vec2 col1, col2; 

    Mat2() = default;
    Mat2(float m00, float m01, float m10, float m11) : col1(m00, m10), col2(m01, m11) {}

    Mat2& operator+=(Mat2 other);
    Mat2& operator-=(Mat2 other);

    Mat2& operator*=(float k);
    Mat2& operator/=(float k);

    Mat2& operator*=(Mat2 other);

    float Determinant() const;
    Mat2 Inverse() const;

    Mat2& Invert();
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