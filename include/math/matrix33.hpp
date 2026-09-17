#pragma once

#include "math/vector3.hpp"
#include <cstddef>

namespace math {

class Matrix33 {
public:
    Matrix33() = default;

    Matrix33(float m00, float m01, float m02,
        float m10, float m11, float m12,
        float m20, float m21, float m22)
        : m_m00(m00), m_m01(m01), m_m02(m02)
        , m_m10(m10), m_m11(m11), m_m12(m12)
        , m_m20(m20), m_m21(m21), m_m22(m22) {}

    Matrix33(const Matrix33& other) 
        : m_m00(other.m_m00), m_m01(other.m_m01), m_m02(other.m_m02)
        , m_m10(other.m_m10), m_m11(other.m_m11), m_m12(other.m_m12)
        , m_m20(other.m_m20), m_m21(other.m_m21), m_m22(other.m_m22) {}

    Matrix33& operator=(const Matrix33& other);

    const Vector3& operator[](std::size_t index) const { return m_rows[index]; }
    Vector3& operator[](std::size_t index) { return m_rows[index]; }

    Matrix33& operator+=(const Matrix33& other);
    Matrix33& operator-=(const Matrix33& other);

    Matrix33& operator*=(float scalar);
    Matrix33& operator/=(float scalar);

    bool IsNull() const;

    float Norm() const;
    void Normalize();

    std::string ToString() const;

private:
    union {
        struct {
            float m_m00, m_m01, m_m02;
            float m_m10, m_m11, m_m12;
            float m_m20, m_m21, m_m22;
        };

        Vector3 m_rows[3];
    };
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