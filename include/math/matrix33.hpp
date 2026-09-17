#pragma once

#include "math/vector3.hpp"
#include <cstddef>

namespace math {

struct Matrix33 {
    union {
        struct {
            float m00, m01, m02;
            float m10, m11, m12;
            float m20, m21, m22;
        };

        Vector3 rows[3];
    };

    Matrix33() = default;

    Matrix33(float m00, float m01, float m02,
        float m10, float m11, float m12,
        float m20, float m21, float m22)
        : m00(m00), m01(m01), m02(m02)
        , m10(m10), m11(m11), m12(m12)
        , m20(m20), m21(m21), m22(m22) {}

    Matrix33(const Matrix33& other) 
        : m00(other.m00), m01(other.m01), m02(other.m02)
        , m10(other.m10), m11(other.m11), m12(other.m12)
        , m20(other.m20), m21(other.m21), m22(other.m22) {}

    const Vector3& operator[](std::size_t index) const { return rows[index]; }
    Vector3& operator[](std::size_t index) { return rows[index]; }

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