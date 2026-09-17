#pragma once

#include "math/vector2.hpp"

struct Matrix22 { 
    Vector2 column1, column2; 
};

bool operator==(const Matrix22& lhs, const Matrix22& rhs);
bool operator!=(const Matrix22& lhs, const Matrix22& rhs);

Matrix22 operator+(const Matrix22& lhs, const Matrix22& rhs);
Matrix22 operator-(const Matrix22& lhs, const Matrix22& rhs);

Matrix22 operator*(const Matrix22& matrix, float scalar);
Matrix22 operator*(float scalar, const Matrix22& matrix);
Matrix22 operator/(const Matrix22& matrix, float scalar);

Matrix22 operator*(const Matrix22& lhs, const Matrix22& rhs);
Vector2 operator*(const Matrix22& matrix, const Vector2& vector);

float Determinant(const Matrix22& matrix);
Matrix22 Inverse(const Matrix22& matrix);