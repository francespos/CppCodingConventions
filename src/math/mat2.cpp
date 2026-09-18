#include "lpx/math/mat2.hpp"

namespace lpx {

bool operator==(const Mat2& lhs, const Mat2& rhs) {  
    return lhs.col1 == rhs.col1 && lhs.col2 == rhs.col2;
}

bool operator!=(const Mat2& lhs, const Mat2& rhs) {
    return lhs.col1 != rhs.col1 || lhs.col2 != rhs.col2;
}

Mat2 operator+(const Mat2& lhs, const Mat2& rhs) {
    Mat2 rslt;

    rslt.col1 = lhs.col1 + rhs.col1; 
    rslt.col2 = lhs.col2 + rhs.col2;

    return rslt;
}

Mat2 operator-(const Mat2& lhs, const Mat2& rhs) {
    Mat2 rslt;

    rslt.col1 = lhs.col1 - rhs.col1; 
    rslt.col2 = lhs.col2 - rhs.col2;

    return rslt;
}

Mat2 operator*(const Mat2& mat, float k) {
    Mat2 rslt;

    rslt.col1 = mat.col1 * k; 
    rslt.col2 = mat.col2 * k;

    return rslt;
}

Mat2 operator*(float k, const Mat2& mat) {
    Mat2 rslt;

    rslt.col1 = mat.col1 * k; 
    rslt.col2 = mat.col2 * k;

    return rslt;
}

Mat2 operator/(const Mat2& mat, float k) {
    Mat2 rslt;

    rslt.col1 = mat.col1 / k; 
    rslt.col2 = mat.col2 / k;

    return rslt;
}

Mat2 operator*(const Mat2& lhs, const Mat2& rhs) {
    Mat2 rslt;

    rslt.col1 = lhs * rhs.col1;
    rslt.col2 = lhs * rhs.col2;

    return rslt;
}

Vec2 operator*(const Mat2& mat, const Vec2& vec) {
    return mat.col1 * vec.x + mat.col2 * vec.y;
}

float Determinant(const Mat2& mat) {
    return mat.col1.x * mat.col2.y - mat.col2.x * mat.col1.y;
}

Mat2 Inverse(const Mat2& mat) {
    auto invDet = 1.0f / Determinant(mat);
    Mat2 rslt;

    rslt.col1.x = mat.col2.y * invDet;
    rslt.col1.y = -mat.col2.x * invDet;
    rslt.col2.x = -mat.col1.y * invDet;
    rslt.col2.y = mat.col1.x * invDet;

    return rslt;
}

} // namespace lpx