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
    return *this *= 1.0f / k;
}

float Vec2::Length() const {
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::Normalized() const {
    return *this / Length();
}

void Vec2::Normalize() {
    *this /= Length();
}

bool operator==(Vec2 lhs, Vec2 rhs) {
    return std::abs(lhs.x - rhs.x) < Epsilon && std::abs(lhs.y - rhs.y) < Epsilon;
}

bool operator!=(Vec2 lhs, Vec2 rhs) {
    return !(lhs == rhs);
}

Vec2 operator+(Vec2 lhs, Vec2 rhs) {
    return lhs += rhs;
}

Vec2 operator-(Vec2 lhs, Vec2 rhs) {
    return lhs -= rhs;
}

Vec2 operator*(Vec2 vec, float k) {
    return vec *= k;
}

Vec2 operator*(float k, Vec2 vec) {
    return vec * k;
}

Vec2 operator/(Vec2 vec, float k) {
    return vec /= k;
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