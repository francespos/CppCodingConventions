#pragma once

#include <cstddef>

struct Vector2 { 
    float x, y; 
};

bool operator==(const Vector2& lhs, const Vector2& rhs);
bool operator!=(const Vector2& lhs, const Vector2& rhs);

Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

Vector2 operator*(const Vector2& vector, float scalar);
Vector2 operator*(float scalar, const Vector2& vector);
Vector2 operator/(const Vector2& vector, float scalar);

float Length(const Vector2& vector);
Vector2 Normalize(const Vector2& vector);

float Dot(const Vector2& lhs, const Vector2& rhs);
float Cross(const Vector2& lhs, const Vector2& rhs);
float Distance(const Vector2& lhs, const Vector2& rhs);