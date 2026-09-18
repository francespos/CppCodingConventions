#include "math/vec2.hpp"
#include "math/float.hpp"
#include <cmath>

bool operator==(const Vec2& lhs, const Vec2& rhs) {
    return std::abs(lhs.x - rhs.x) < Epsilon && std::abs(lhs.y - rhs.y) < Epsilon;
}

bool operator!=(const Vec2& lhs, const Vec2& rhs) {
    return std::abs(lhs.x - rhs.x) >= Epsilon || std::abs(lhs.y - rhs.y) >= Epsilon;
}

Vec2 operator+(const Vec2& lhs, const Vec2& rhs) {
    Vec2 result;

    result.x = lhs.x + rhs.x;
    result.y = lhs.y + rhs.y;

    return result;
}

Vec2 operator-(const Vec2& lhs, const Vec2& rhs) {
    Vec2 result;

    result.x = lhs.x - rhs.x;
    result.y = lhs.y - rhs.y;

    return result;
}

Vec2 operator*(const Vec2& vector, float scalar) {
    Vec2 result;

    result.x = vector.x * scalar;
    result.y = vector.y * scalar;

    return result;
}

Vec2 operator*(float scalar, const Vec2& vector) {
    Vec2 result;

    result.x = vector.x * scalar;
    result.y = vector.y * scalar;

    return result;
}

Vec2 operator/(const Vec2& vector, float scalar) {
    Vec2 result;

    result.x = vector.x / scalar;
    result.y = vector.y / scalar;

    return result;
}

float Length(const Vec2& vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

Vec2 Normalize(const Vec2& vector) {
    auto length = Length(vector);
    Vec2 result;

    result.x = vector.x / length;
    result.y = vector.y / length;

    return result;
}

float Dot(const Vec2& lhs, const Vec2& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

float Cross(const Vec2& lhs, const Vec2& rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

float Distance(const Vec2& lhs, const Vec2& rhs) {
    return Length(lhs - rhs);
}