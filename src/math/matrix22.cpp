#include "math/matrix22.hpp"

bool operator==(const Matrix22& lhs, const Matrix22& rhs) {  
    return lhs.column1 == rhs.column1 && lhs.column2 == rhs.column2;
}

bool operator!=(const Matrix22& lhs, const Matrix22& rhs) {
    return lhs.column1 != rhs.column1 || lhs.column2 != rhs.column2;
}

Matrix22 operator+(const Matrix22& lhs, const Matrix22& rhs) {
    Matrix22 result;

    result.column1 = lhs.column1 + rhs.column1; 
    result.column2 = lhs.column2 + rhs.column2;

    return result;
}

Matrix22 operator-(const Matrix22& lhs, const Matrix22& rhs) {
    Matrix22 result;

    result.column1 = lhs.column1 - rhs.column1; 
    result.column2 = lhs.column2 - rhs.column2;

    return result;
}

Matrix22 operator*(const Matrix22& matrix, float scalar) {
    Matrix22 result;

    result.column1 = matrix.column1 * scalar; 
    result.column2 = matrix.column2 * scalar;

    return result;
}

Matrix22 operator*(float scalar, const Matrix22& matrix) {
    Matrix22 result;

    result.column1 = matrix.column1 * scalar; 
    result.column2 = matrix.column2 * scalar;

    return result;
}

Matrix22 operator/(const Matrix22& matrix, float scalar) {
    Matrix22 result;

    result.column1 = matrix.column1 / scalar; 
    result.column2 = matrix.column2 / scalar;

    return result;
}

Matrix22 operator*(const Matrix22& lhs, const Matrix22& rhs) {
    Matrix22 result;

    result.column1 = lhs * rhs.column1;
    result.column2 = lhs * rhs.column2;

    return result;
}

Vector2 operator*(const Matrix22& matrix, const Vector2& vector) {
    return matrix.column1 * vector.x + matrix.column2 * vector.y;
}

float Determinant(const Matrix22& matrix) {
    return matrix.column1.x * matrix.column2.y - matrix.column2.x * matrix.column1.y;
}

Matrix22 Inverse(const Matrix22& matrix) {
    auto inverseDeterminant = 1.0f / Determinant(matrix);
    Matrix22 result;

    result.column1.x = +matrix.column2.y * inverseDeterminant;
    result.column1.y = -matrix.column2.x * inverseDeterminant;
    result.column2.x = -matrix.column1.y * inverseDeterminant;
    result.column2.y = +matrix.column1.x * inverseDeterminant;

    return result;
}