#include <math/Vector3d.hpp>

#include <math/defs.hpp>

#include <cmath>
#include <sstream>

namespace math {

bool Vector3d::IsNull() const 
{
    return *this == Vector3d{0.0f, 0.0f, 0.0f};
}

float Vector3d::Norm() const 
{
    return std::sqrt(x * x + y * y + z * z);
}

void Vector3d::Normalize()
{
    auto norm{Norm()};

    x /= norm;
    y /= norm;
    z /= norm;
}

std::string Vector3d::ToString() const
{
    std::ostringstream outputStringStream;
    outputStringStream << "[" << x << ", " << y << ", " << z << "]";
    return outputStringStream.str();
}

bool operator==(const Vector3d& lhs, const Vector3d& rhs) 
{
    if (std::abs(lhs.x - rhs.x) < detail::k_epsilon && 
        std::abs(lhs.y - rhs.y) < detail::k_epsilon &&
        std::abs(lhs.z - rhs.z) < detail::k_epsilon)
    {
        return true;
    }

    return false;
}

bool operator!=(const Vector3d& lhs, const Vector3d& rhs)
{
    return !(lhs == rhs);
}

Vector3d operator+(const Vector3d& lhs, const Vector3d& rhs)
{
    Vector3d result{lhs};

    result.x += rhs.x;
    result.y += rhs.y;
    result.z += rhs.z;

    return result;
}

Vector3d operator-(const Vector3d& lhs, const Vector3d& rhs)
{
    Vector3d result{lhs};

    result.x -= rhs.x;
    result.y -= rhs.y;
    result.z -= rhs.z;

    return result;
}

float Dot(const Vector3d& lhs, const Vector3d& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

Vector3d Cross(const Vector3d& lhs, const Vector3d& rhs)
{
    auto x{lhs.y * rhs.z - lhs.z * rhs.y};
    auto y{lhs.z * rhs.x - lhs.x * rhs.z}; 
    auto z{lhs.x * rhs.y - lhs.y * rhs.x};

    return Vector3d{x, y, z};
}

Vector3d operator*(float scalar, const Vector3d& vector)
{
    Vector3d result{vector};

    result.x *= scalar;
    result.y *= scalar;
    result.z *= scalar;

    return result;
}

Vector3d operator*(const Vector3d& vector, float scalar)
{
    Vector3d result{vector};

    result.x *= scalar;
    result.y *= scalar;
    result.z *= scalar;

    return result;
}

Vector3d operator/(const Vector3d& vector, float scalar)
{
    Vector3d result{vector};

    result.x /= scalar;
    result.y /= scalar;
    result.z /= scalar;

    return result;
}

std::ostream& operator<<(std::ostream& outputStream, const Vector3d& vector)
{
    outputStream << vector.ToString();
    return outputStream;
}

float Distance(const Vector3d& lhs, const Vector3d& rhs)
{
    return (lhs - rhs).Norm();
}

} // namespace math