#include "lpx/math/vec2.hpp"
#include "lpx/math/float.hpp"
#include <cmath>

namespace lpx {

Vec2& Vec2::operator+=(Vec2 other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2& Vec2::operator-=(Vec2 other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2& Vec2::operator*=(float k) {
    x *= k;
    y *= k;
    return *this;
}

Vec2& Vec2::operator/=(float k) {
    x /= k;
    y /= k;
    return *this;
}

float Vec2::Length() const {
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::Normalized() const {
    auto len = Length();
    Vec2 rslt;

    rslt.x = x / len;
    rslt.y = y / len;

    return rslt;
}

void Vec2::Normalize() {
    auto len = Length();
    x /= len;
    y /= len;
}

bool operator==(Vec2 lhs, Vec2 rhs) {
    return std::abs(lhs.x - rhs.x) < Epsilon && std::abs(lhs.y - rhs.y) < Epsilon;
}

bool operator!=(Vec2 lhs, Vec2 rhs) {
    return std::abs(lhs.x - rhs.x) >= Epsilon || std::abs(lhs.y - rhs.y) >= Epsilon;
}

Vec2 operator+(Vec2 lhs, Vec2 rhs) {
    Vec2 rslt;

    rslt.x = lhs.x + rhs.x;
    rslt.y = lhs.y + rhs.y;

    return rslt;
}

Vec2 operator-(Vec2 lhs, Vec2 rhs) {
    Vec2 rslt;

    rslt.x = lhs.x - rhs.x;
    rslt.y = lhs.y - rhs.y;

    return rslt;
}

Vec2 operator*(Vec2 vec, float k) {
    Vec2 rslt;

    rslt.x = vec.x * k;
    rslt.y = vec.y * k;

    return rslt;
}

Vec2 operator*(float k, Vec2 vec) {
    Vec2 rslt;

    rslt.x = vec.x * k;
    rslt.y = vec.y * k;

    return rslt;
}

Vec2 operator/(Vec2 vec, float k) {
    Vec2 rslt;

    rslt.x = vec.x / k;
    rslt.y = vec.y / k;

    return rslt;
}

float Dot(Vec2 lhs, Vec2 rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

float Cross(Vec2 lhs, Vec2 rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

float Distance(Vec2 lhs, Vec2 rhs) {
    return (lhs - rhs).Length();
}

} // namespace lpx