#pragma once

#include <cstddef>

namespace lpx {

struct Vec2 { 
    float x, y; 

    Vec2() = default;
    Vec2(float x, float y) : x(x), y(y) {}

    Vec2& operator+=(Vec2 other);
    Vec2& operator-=(Vec2 other);

    Vec2& operator*=(float k);
    Vec2& operator/=(float k);

    float Length() const;
    Vec2 Normalized() const;

    Vec2& Normalize();
};

bool operator==(Vec2 lhs, Vec2 rhs);
bool operator!=(Vec2 lhs, Vec2 rhs);

Vec2 operator+(Vec2 lhs, Vec2 rhs);
Vec2 operator-(Vec2 lhs, Vec2 rhs);

Vec2 operator*(Vec2 vec, float k);
Vec2 operator*(float k, Vec2 vec);
Vec2 operator/(Vec2 vec, float k);

float Dot(Vec2 lhs, Vec2 rhs);
float Cross(Vec2 lhs, Vec2 rhs);
float Distance(Vec2 lhs, Vec2 rhs);

} // namespace lpx