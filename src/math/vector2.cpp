#include "math/vector2.hpp"
#include "math/precision.hpp"
#include <cmath>

bool operator==(const Vector2& lhs, const Vector2& rhs) {
    return std::abs(lhs.x - rhs.x) < Epsilon && std::abs(lhs.y - rhs.y) < Epsilon;
}

bool operator!=(const Vector2& lhs, const Vector2& rhs) {
    return std::abs(lhs.x - rhs.x) >= Epsilon || std::abs(lhs.y - rhs.y) >= Epsilon;
}

Vector2 operator+(const Vector2& lhs, const Vector2& rhs) {
    Vector2 result;

    result.x = lhs.x + rhs.x;
    result.y = lhs.y + rhs.y;

    return result;
}

Vector2 operator-(const Vector2& lhs, const Vector2& rhs) {
    Vector2 result;

    result.x = lhs.x - rhs.x;
    result.y = lhs.y - rhs.y;

    return result;
}

Vector2 operator*(const Vector2& vector, float scalar) {
    Vector2 result;

    result.x = vector.x * scalar;
    result.y = vector.y * scalar;

    return result;
}

Vector2 operator*(float scalar, const Vector2& vector) {
    Vector2 result;

    result.x = vector.x * scalar;
    result.y = vector.y * scalar;

    return result;
}

Vector2 operator/(const Vector2& vector, float scalar) {
    Vector2 result;

    result.x = vector.x / scalar;
    result.y = vector.y / scalar;

    return result;
}

float Length(const Vector2& vector) {
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

Vector2 Normalize(const Vector2& vector) {
    auto length = Length(vector);
    Vector2 result;

    result.x = vector.x / length;
    result.y = vector.y / length;

    return result;
}

float Dot(const Vector2& lhs, const Vector2& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

float Cross(const Vector2& lhs, const Vector2& rhs) {
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

float Distance(const Vector2& lhs, const Vector2& rhs) {
    return Length(lhs - rhs);
}