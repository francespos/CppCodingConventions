#include "lpx/math/vec2.hpp"
#include "lpx/math/float.hpp"
#include <cmath>

namespace lpx {

bool operator==(const Vec2& lhs, const Vec2& rhs) {
    return std::abs(lhs.x - rhs.x) < Epsilon && std::abs(lhs.y - rhs.y) < Epsilon;
}

bool operator!=(const Vec2& lhs, const Vec2& rhs) {
    return std::abs(lhs.x - rhs.x) >= Epsilon || std::abs(lhs.y - rhs.y) >= Epsilon;
}

Vec2 operator+(const Vec2& lhs, const Vec2& rhs) {
    Vec2 rslt;

    rslt.x = lhs.x + rhs.x;
    rslt.y = lhs.y + rhs.y;

    return rslt;
}

Vec2 operator-(const Vec2& lhs, const Vec2& rhs) {
    Vec2 rslt;

    rslt.x = lhs.x - rhs.x;
    rslt.y = lhs.y - rhs.y;

    return rslt;
}

Vec2 operator*(const Vec2& vec, float k) {
    Vec2 rslt;

    rslt.x = vec.x * k;
    rslt.y = vec.y * k;

    return rslt;
}

Vec2 operator*(float k, const Vec2& vec) {
    Vec2 rslt;

    rslt.x = vec.x * k;
    rslt.y = vec.y * k;

    return rslt;
}

Vec2 operator/(const Vec2& vec, float k) {
    Vec2 rslt;

    rslt.x = vec.x / k;
    rslt.y = vec.y / k;

    return rslt;
}

float Length(const Vec2& vec) {
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

Vec2 Normalize(const Vec2& vec) {
    auto len = Length(vec);
    Vec2 rslt;

    rslt.x = vec.x / len;
    rslt.y = vec.y / len;

    return rslt;
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

} // namespace lpx