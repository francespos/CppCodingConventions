#pragma once

#include "math/vec2.hpp"

struct Mat22 { 
    Vec2 col1, col2; 
};

bool operator==(const Mat22& lhs, const Mat22& rhs);
bool operator!=(const Mat22& lhs, const Mat22& rhs);

Mat22 operator+(const Mat22& lhs, const Mat22& rhs);
Mat22 operator-(const Mat22& lhs, const Mat22& rhs);

Mat22 operator*(const Mat22& matrix, float scalar);
Mat22 operator*(float scalar, const Mat22& matrix);
Mat22 operator/(const Mat22& matrix, float scalar);

Mat22 operator*(const Mat22& lhs, const Mat22& rhs);
Vec2 operator*(const Mat22& matrix, const Vec2& vector);

float Determinant(const Mat22& matrix);
Mat22 Inverse(const Mat22& matrix);