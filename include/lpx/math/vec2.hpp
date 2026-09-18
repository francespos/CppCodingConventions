#pragma once

#include <cstddef>

namespace lpx {

struct Vec2 { 
    float x, y; 
};

bool operator==(const Vec2& lhs, const Vec2& rhs);
bool operator!=(const Vec2& lhs, const Vec2& rhs);

Vec2 operator+(const Vec2& lhs, const Vec2& rhs);
Vec2 operator-(const Vec2& lhs, const Vec2& rhs);

Vec2 operator*(const Vec2& vec, float k);
Vec2 operator*(float k, const Vec2& vec);
Vec2 operator/(const Vec2& vec, float k);

float Length(const Vec2& vec);
Vec2 Normalize(const Vec2& vec);

float Dot(const Vec2& lhs, const Vec2& rhs);
float Cross(const Vec2& lhs, const Vec2& rhs);
float Distance(const Vec2& lhs, const Vec2& rhs);

} // namespace lpx