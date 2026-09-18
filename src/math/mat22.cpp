#include "math/mat22.hpp"

bool operator==(const Mat22& lhs, const Mat22& rhs) {  
    return lhs.col1 == rhs.col1 && lhs.col2 == rhs.col2;
}

bool operator!=(const Mat22& lhs, const Mat22& rhs) {
    return lhs.col1 != rhs.col1 || lhs.col2 != rhs.col2;
}

Mat22 operator+(const Mat22& lhs, const Mat22& rhs) {
    Mat22 result;

    result.col1 = lhs.col1 + rhs.col1; 
    result.col2 = lhs.col2 + rhs.col2;

    return result;
}

Mat22 operator-(const Mat22& lhs, const Mat22& rhs) {
    Mat22 result;

    result.col1 = lhs.col1 - rhs.col1; 
    result.col2 = lhs.col2 - rhs.col2;

    return result;
}

Mat22 operator*(const Mat22& matrix, float scalar) {
    Mat22 result;

    result.col1 = matrix.col1 * scalar; 
    result.col2 = matrix.col2 * scalar;

    return result;
}

Mat22 operator*(float scalar, const Mat22& matrix) {
    Mat22 result;

    result.col1 = matrix.col1 * scalar; 
    result.col2 = matrix.col2 * scalar;

    return result;
}

Mat22 operator/(const Mat22& matrix, float scalar) {
    Mat22 result;

    result.col1 = matrix.col1 / scalar; 
    result.col2 = matrix.col2 / scalar;

    return result;
}

Mat22 operator*(const Mat22& lhs, const Mat22& rhs) {
    Mat22 result;

    result.col1 = lhs * rhs.col1;
    result.col2 = lhs * rhs.col2;

    return result;
}

Vec2 operator*(const Mat22& matrix, const Vec2& vector) {
    return matrix.col1 * vector.x + matrix.col2 * vector.y;
}

float Determinant(const Mat22& matrix) {
    return matrix.col1.x * matrix.col2.y - matrix.col2.x * matrix.col1.y;
}

Mat22 Inverse(const Mat22& matrix) {
    auto invDet = 1.0f / Determinant(matrix);
    Mat22 result;

    result.col1.x = matrix.col2.y * invDet;
    result.col1.y = -matrix.col2.x * invDet;
    result.col2.x = -matrix.col1.y * invDet;
    result.col2.y = matrix.col1.x * invDet;

    return result;
}