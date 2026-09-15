#pragma once

#include <cstddef>
#include <ostream>

namespace math {

struct Vector3d
{
    float x;
    float y;
    float z;

    Vector3d(float x, float y, float z)
        : x{x}, y{y}, z{z}
    {
    }

    Vector3d(const Vector3d& other)
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

bool operator==(const Vector3d& lhs, const Vector3d& rhs);
bool operator!=(const Vector3d& lhs, const Vector3d& rhs);

Vector3d operator+(const Vector3d& lhs, const Vector3d& rhs);
Vector3d operator-(const Vector3d& lhs, const Vector3d& rhs);

float Dot(const Vector3d& lhs, const Vector3d& rhs);
Vector3d Cross(const Vector3d& lhs, const Vector3d& rhs);

Vector3d operator*(float scalar, const Vector3d& vector);
Vector3d operator*(const Vector3d& vector, float scalar);
Vector3d operator/(const Vector3d& vector, float scalar);

std::ostream& operator<<(std::ostream& outputStream, const Vector3d& vector);

float Distance(const Vector3d& lhs, const Vector3d& rhs);

} // namespace math