#pragma once

#include "math/Vector3.hpp"

#include <cstddef>

namespace math {

struct Matrix33
{
    union 
    {
        struct 
        {
            float m00, m01, m02;
            float m10, m11, m12;
            float m20, m21, m22;
        };

        float entries[9];
        Vector3 rows[3];
    };

    const Vector3& operator[](std::size_t index) const
    {
        return rows[index];
    }

    Vector3& operator[](std::size_t index)
    {
        return rows[index];
    }

    Matrix33& operator+=(const Matrix33& other);
    Matrix33& operator-=(const Matrix33& other);

    Matrix33& operator*=(float scalar);
    Matrix33& operator/=(float scalar);

    bool IsNull() const;

    float Norm() const;
    void Normalize();

    std::string ToString() const;
};

bool operator==(const Matrix33& lhs, const Matrix33& rhs);
bool operator!=(const Matrix33& lhs, const Matrix33& rhs);

Matrix33 operator+(const Matrix33& lhs, const Matrix33& rhs);
Matrix33 operator-(const Matrix33& lhs, const Matrix33& rhs);

Matrix33 operator*(const Matrix33& lhs, const Matrix33& rhs);

Matrix33 operator*(float scalar, const Matrix33& matrix);
Matrix33 operator*(const Matrix33& matrix, float scalar);
Matrix33 operator/(const Matrix33& matrix, float scalar);

Vector3 operator*(const Matrix33& matrix, const Vector3& vector);

std::ostream& operator<<(std::ostream& outputStream, const Matrix33& matrix);

} // namespace math