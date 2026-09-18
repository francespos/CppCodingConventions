#pragma once

#include <cstddef>

struct Vec2 { 
    float x, y; 
};

bool operator==(const Vec2& lhs, const Vec2& rhs);
bool operator!=(const Vec2& lhs, const Vec2& rhs);

Vec2 operator+(const Vec2& lhs, const Vec2& rhs);
Vec2 operator-(const Vec2& lhs, const Vec2& rhs);

Vec2 operator*(const Vec2& vector, float scalar);
Vec2 operator*(float scalar, const Vec2& vector);
Vec2 operator/(const Vec2& vector, float scalar);

float Length(const Vec2& vector);
Vec2 Normalize(const Vec2& vector);

float Dot(const Vec2& lhs, const Vec2& rhs);
float Cross(const Vec2& lhs, const Vec2& rhs);
float Distance(const Vec2& lhs, const Vec2& rhs);