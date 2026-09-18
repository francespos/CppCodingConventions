#pragma once

#include "lpx/math/vec2.hpp"

namespace lpx {

struct Mat2 { 
    Vec2 col1, col2; 
};

bool operator==(const Mat2& lhs, const Mat2& rhs);
bool operator!=(const Mat2& lhs, const Mat2& rhs);

Mat2 operator+(const Mat2& lhs, const Mat2& rhs);
Mat2 operator-(const Mat2& lhs, const Mat2& rhs);

Mat2 operator*(const Mat2& mat, float k);
Mat2 operator*(float k, const Mat2& mat);
Mat2 operator/(const Mat2& mat, float k);

Mat2 operator*(const Mat2& lhs, const Mat2& rhs);
Vec2 operator*(const Mat2& mat, const Vec2& vec);

float Determinant(const Mat2& mat);
Mat2 Inverse(const Mat2& mat);

} // namespace lpx