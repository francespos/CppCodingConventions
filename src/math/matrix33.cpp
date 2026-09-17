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
    return std::sqrt(m00 * m00 + m01 * m01 + m02 * m02 +
        m10 * m10 + m11 * m11 + m12 * m12 + 
        m20 * m20 + m21 * m21 + m22 * m22);
}

void Matrix33::Normalize() {
    auto norm = Norm();

    rows[0] /= norm;
    rows[1] /= norm;
    rows[2] /= norm;
}

std::string Matrix33::ToString() const {
    std::ostringstream outputStringStream;
    outputStringStream << rows[0] << ", " << rows[1] << ", " << rows[2];
    return outputStringStream.str();
}

bool operator==(const Matrix33& lhs, const Matrix33& rhs) {  
    return lhs.rows[0] == rhs.rows[0] &&
        lhs.rows[1] == rhs.rows[1] &&
        lhs.rows[2] == rhs.rows[2];
}

bool operator!=(const Matrix33& lhs, const Matrix33& rhs) {
    return !(lhs == rhs);
}

Matrix33 operator+(const Matrix33& lhs, const Matrix33& rhs) {
    Matrix33 result{lhs};

    result.rows[0] += rhs.rows[0];
    result.rows[1] += rhs.rows[1];
    result.rows[2] += rhs.rows[2];

    return result;
}

Matrix33 operator-(const Matrix33& lhs, const Matrix33& rhs) {
    Matrix33 result(lhs);

    result.rows[0] -= rhs.rows[0];
    result.rows[1] -= rhs.rows[1];
    result.rows[2] -= rhs.rows[2];

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

    result.rows[0] *= scalar;
    result.rows[1] *= scalar;
    result.rows[2] *= scalar;

    return result;
}

Matrix33 operator/(const Matrix33& matrix, float scalar) {
    Matrix33 result(matrix);

    result.rows[0] /= scalar;
    result.rows[1] /= scalar;
    result.rows[2] /= scalar;

    return result;
}

Vector3 operator*(const Matrix33& matrix, const Vector3& vector) {
    auto x = Vector3::Dot(matrix.rows[0], vector);
    auto y = Vector3::Dot(matrix.rows[1], vector);
    auto z = Vector3::Dot(matrix.rows[2], vector);

    return Vector3(x, y, z);
}

std::ostream& operator<<(std::ostream& outputStream, const Matrix33& matrix) {
    outputStream << matrix;
    return outputStream;
}

} // namespace math