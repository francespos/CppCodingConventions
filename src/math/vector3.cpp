#include "math/vector3.hpp"
#include "math/detail/precision.hpp"
#include <cmath>
#include <sstream>
#include <string>

namespace math {

float Vector3::Dot(const Vector3& lhs, const Vector3& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

Vector3 Vector3::Cross(const Vector3& lhs, const Vector3& rhs) {
    auto x = lhs.y * rhs.z - lhs.z * rhs.y;
    auto y = lhs.z * rhs.x - lhs.x * rhs.z; 
    auto z = lhs.x * rhs.y - lhs.y * rhs.x;

    return Vector3(x, y, z);
}

float Vector3::Distance(const Vector3& lhs, const Vector3& rhs) {
    return (lhs - rhs).Norm();
}

Vector3& Vector3::operator+=(const Vector3& other) {
    *this = *this + other;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other) {
    *this = *this - other;
    return *this;   
}

Vector3& Vector3::operator*=(float scalar) {
    *this = *this * scalar;
    return *this;
}

Vector3& Vector3::operator/=(float scalar) {
    *this = *this / scalar;
    return *this;
}

bool Vector3::IsNull() const {
    return *this == Vector3{0.0f, 0.0f, 0.0f};
}

float Vector3::Norm() const {
    return std::sqrt(x * x + y * y + z * z);
}

void Vector3::Normalize() {
    auto norm = Norm();

    x /= norm;
    y /= norm;
    z /= norm;
}

std::string Vector3::ToString() const {
    std::ostringstream outputStringStream;
    outputStringStream << "[" << x << ", " << y << ", " << z << "]";
    return outputStringStream.str();
}

bool operator==(const Vector3& lhs, const Vector3& rhs) {
    if (std::abs(lhs.x - rhs.x) < detail::Epsilon && 
        std::abs(lhs.y - rhs.y) < detail::Epsilon &&
        std::abs(lhs.z - rhs.z) < detail::Epsilon) 
    {
        return true;
    }

    return false;
}

bool operator!=(const Vector3& lhs, const Vector3& rhs) {
    return !(lhs == rhs);
}

Vector3 operator+(const Vector3& lhs, const Vector3& rhs) {
    Vector3 result(lhs);

    result.x += rhs.x;
    result.y += rhs.y;
    result.z += rhs.z;

    return result;
}

Vector3 operator-(const Vector3& lhs, const Vector3& rhs) {
    Vector3 result(lhs);

    result.x -= rhs.x;
    result.y -= rhs.y;
    result.z -= rhs.z;

    return result;
}

Vector3 operator*(float scalar, const Vector3& vector) {
    return vector * scalar;
}

Vector3 operator*(const Vector3& vector, float scalar) {
    Vector3 result(vector);

    result.x *= scalar;
    result.y *= scalar;
    result.z *= scalar;

    return result;
}

Vector3 operator/(const Vector3& vector, float scalar) {
    Vector3 result(vector);

    result.x /= scalar;
    result.y /= scalar;
    result.z /= scalar;

    return result;
}

std::ostream& operator<<(std::ostream& outputStream, const Vector3& vector) {
    outputStream << vector.ToString();
    return outputStream;
}

} // namespace math