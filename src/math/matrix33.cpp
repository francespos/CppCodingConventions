#include "math/matrix33.hpp"
#include <cmath>
#include <sstream>

namespace math {

Matrix33& Matrix33::operator+=(const Matrix33& other) {
    *this = *this + other;
    return *this;
}

Matrix33& Matrix33::operator-=(const Matrix33& other) {
    *this = *this - other;
    return *this;
}

Matrix33& Matrix33::operator*=(float scalar) {
    *this = *this * scalar;
    return *this;
}

Matrix33& Matrix33::operator/=(float scalar) {
    *this = *this / scalar;
    return *this;
}

bool Matrix33::IsNull() const {
    return *this == Matrix33();
}

float Matrix33::Norm() const {
    return std::sqrt(m_m00 * m_m00 + m_m01 * m_m01 + m_m02 * m_m02 +
        m_m10 * m_m10 + m_m11 * m_m11 + m_m12 * m_m12 + 
        m_m20 * m_m20 + m_m21 * m_m21 + m_m22 * m_m22);
}

void Matrix33::Normalize() {
    auto norm = Norm();

    m_rows[0] /= norm;
    m_rows[1] /= norm;
    m_rows[2] /= norm;
}

std::string Matrix33::ToString() const {
    std::ostringstream outputStringStream;
    outputStringStream << m_rows[0] << ", " << m_rows[1] << ", " << m_rows[2];
    return outputStringStream.str();
}

bool operator==(const Matrix33& lhs, const Matrix33& rhs) {  
    return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
}

bool operator!=(const Matrix33& lhs, const Matrix33& rhs) {
    return !(lhs == rhs);
}

Matrix33 operator+(const Matrix33& lhs, const Matrix33& rhs) {
    Matrix33 result(lhs);

    result[0] += rhs[0];
    result[1] += rhs[1];
    result[2] += rhs[2];

    return result;
}

Matrix33 operator-(const Matrix33& lhs, const Matrix33& rhs) {
    Matrix33 result(lhs);

    result[0] -= rhs[0];
    result[1] -= rhs[1];
    result[2] -= rhs[2];

    return result;
}

Matrix33 operator*(const Matrix33& lhs, const Matrix33& rhs) {
    Matrix33 result{};

    for (std::size_t i = 0; i < 3; ++i) {
        for (std::size_t k = 0; k < 3; ++k) {
            for (std::size_t j = 0; j < 3; ++j) {
                result[i][j] += lhs[i][k] * rhs[k][j];
            }
        }
    }

    return result;
}

Matrix33 operator*(float scalar, const Matrix33& matrix) {
    return matrix * scalar;
}

Matrix33 operator*(const Matrix33& matrix, float scalar) {
    Matrix33 result(matrix);

    result[0] *= scalar;
    result[1] *= scalar;
    result[2] *= scalar;

    return result;
}

Matrix33 operator/(const Matrix33& matrix, float scalar) {
    Matrix33 result(matrix);

    result[0] /= scalar;
    result[1] /= scalar;
    result[2] /= scalar;

    return result;
}

Vector3 operator*(const Matrix33& matrix, const Vector3& vector) {
    auto x = Dot(matrix[0], vector);
    auto y = Dot(matrix[1], vector);
    auto z = Dot(matrix[2], vector);

    return Vector3(x, y, z);
}

std::ostream& operator<<(std::ostream& outputStream, const Matrix33& matrix) {
    outputStream << matrix.ToString();
    return outputStream;
}

} // namespace math