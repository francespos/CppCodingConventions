#include "lpx/math/mat2.hpp"

namespace lpx {

Mat2& Mat2::operator+=(Mat2 other) {
    col1 = col1 + other.col1;
    col2 = col2 + other.col2;
    return *this;
}

Mat2& Mat2::operator-=(Mat2 other) {
    col1 = col1 - other.col1;
    col2 = col2 - other.col2;
    return *this;
}

Mat2& Mat2::operator*=(float k) {
    col1 = col1 * k;
    col2 = col2 * k;
    return *this;
}

Mat2& Mat2::operator/=(float k) {
    col1 = col1 / k;
    col2 = col2 / k;
    return *this;
}

float Mat2::Determinant() const {
    return col1.x * col2.y - col2.x * col1.y;
}

Mat2 Mat2::Inverse() const {
    auto det = Determinant();
    Mat2 rslt;

    rslt.col1.x =  col2.y / det;
    rslt.col1.y = -col2.x / det;
    rslt.col2.x = -col1.y / det;
    rslt.col2.y =  col1.x / det;

    return rslt;
}

void Mat2::Invert() {
    auto det = Determinant();
    Mat2 rslt;

    rslt.col1.x =  col2.y / det;
    rslt.col1.y = -col2.x / det;
    rslt.col2.x = -col1.y / det;
    rslt.col2.y =  col1.x / det;

    *this = rslt;
}

bool operator==(Mat2 lhs, Mat2 rhs) {  
    return lhs.col1 == rhs.col1 && lhs.col2 == rhs.col2;
}

bool operator!=(Mat2 lhs, Mat2 rhs) {
    return lhs.col1 != rhs.col1 || lhs.col2 != rhs.col2;
}

Mat2 operator+(Mat2 lhs, Mat2 rhs) {
    Mat2 rslt;

    rslt.col1 = lhs.col1 + rhs.col1; 
    rslt.col2 = lhs.col2 + rhs.col2;

    return rslt;
}

Mat2 operator-(Mat2 lhs, Mat2 rhs) {
    Mat2 rslt;

    rslt.col1 = lhs.col1 - rhs.col1; 
    rslt.col2 = lhs.col2 - rhs.col2;

    return rslt;
}

Mat2 operator*(Mat2 mat, float k) {
    Mat2 rslt;

    rslt.col1 = mat.col1 * k; 
    rslt.col2 = mat.col2 * k;

    return rslt;
}

Mat2 operator*(float k, Mat2 mat) {
    Mat2 rslt;

    rslt.col1 = mat.col1 * k; 
    rslt.col2 = mat.col2 * k;

    return rslt;
}

Mat2 operator/(Mat2 mat, float k) {
    Mat2 rslt;

    rslt.col1 = mat.col1 / k; 
    rslt.col2 = mat.col2 / k;

    return rslt;
}

Mat2 operator*(Mat2 lhs, Mat2 rhs) {
    Mat2 rslt;

    rslt.col1 = lhs * rhs.col1;
    rslt.col2 = lhs * rhs.col2;

    return rslt;
}

Vec2 operator*(Mat2 mat, Vec2 vec) {
    return mat.col1 * vec.x + mat.col2 * vec.y;
}

} // namespace lpx