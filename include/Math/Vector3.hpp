#pragma once

#include <cstddef>
#include <ostream>

namespace Math {

struct Vector3
{
    float x;
    float y;
    float z;

    Vector3(float x, float y, float z)
        : x{x}, y{y}, z{z}
    {
    }

    Vector3(const Vector3& other)
        : x{other.x}, y{other.y}, z{other.z}
    {
    }

    float operator[](std::size_t index) const 
    {
        return *(&x + index);
    }

    float& operator[](std::size_t index)
    {
        return *(&x + index);
    }

    bool IsNull() const;

    float Norm() const;
    void Normalize();

    std::string ToString() const;
};

bool operator==(const Vector3& lhs, const Vector3& rhs);
bool operator!=(const Vector3& lhs, const Vector3& rhs);

Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
Vector3 operator-(const Vector3& lhs, const Vector3& rhs);

float operator*(const Vector3& lhs, const Vector3& rhs);
Vector3 operator^(const Vector3& lhs, const Vector3& rhs);

Vector3 operator*(float scalar, const Vector3& vector);
Vector3 operator*(const Vector3& vector, float scalar);
Vector3 operator/(const Vector3& vector, float scalar);

std::ostream& operator<<(std::ostream& outputStream, const Vector3& vector);

float Distance(const Vector3& lhs, const Vector3& rhs);

} // namespace Math