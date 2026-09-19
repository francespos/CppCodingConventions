#include "lpx/math/mat2.hpp"

namespace lpx {

Mat2& Mat2::operator+=(Mat2 other) {
    col1 += other.col1;
    col2 += other.col2;
    return *this;
}

Mat2& Mat2::operator-=(Mat2 other) {
    col1 -= other.col1;
    col2 -= other.col2;
    return *this;
}

Mat2& Mat2::operator*=(float k) {
    col1 *= k;
    col2 *= k;
    return *this;
}

Mat2& Mat2::operator/=(float k) {
    return *this *= (1.0f / k);
}

Mat2& Mat2::operator*=(Mat2 other) {
    return *this = *this * other;
}

float Mat2::Determinant() const {
    return col1.x * col2.y - col2.x * col1.y;
}

Mat2 Mat2::Inverse() const {
    auto inv_det = 1.0f / Determinant();
    Mat2 rslt;

    rslt.col1.x =  col2.y * inv_det;
    rslt.col1.y = -col2.x * inv_det;
    rslt.col2.x = -col1.y * inv_det;
    rslt.col2.y =  col1.x * inv_det;

    return rslt;
}

Mat2& Mat2::Invert() {
    return *this = Inverse();
}

bool operator==(Mat2 lhs, Mat2 rhs) {  
    return lhs.col1 == rhs.col1 && lhs.col2 == rhs.col2;
}

bool operator!=(Mat2 lhs, Mat2 rhs) {
    return !(lhs == rhs);
}

Mat2 operator+(Mat2 lhs, Mat2 rhs) {
    return lhs += rhs;
}

Mat2 operator-(Mat2 lhs, Mat2 rhs) {
    return lhs -= rhs;
}

Mat2 operator*(Mat2 mat, float k) {
    return mat *= k;
}

Mat2 operator*(float k, Mat2 mat) {
    return mat * k;
}

Mat2 operator/(Mat2 mat, float k) {
    return mat /= k;
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