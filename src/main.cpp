#include "math/vector3.hpp"
#include <iostream>

int main() {
    math::Vector3 vector(1.0f, 2.34f, -8.553f);

    std::cout << "vector.x = " << vector.x << "\n";
    std::cout << "vector.y = " << vector.y << "\n";
    std::cout << "vector.z = " << vector.z << "\n\n";

    std::cout << "vector[0] = " << vector[0] << "\n";
    std::cout << "vector[1] = " << vector[1] << "\n";
    std::cout << "vector[2] = " << vector[2] << "\n\n";

    auto isNull = vector.IsNull() ? "Yes" : "No";
    std::cout << "Is vector null? " << isNull << "\n\n";

    math::Vector3 vector1(98.3332f, -22.3432f, 399.3029f);
    math::Vector3 vector2(-33.3554f, 885.03f, -135.44f);

    std::cout << "vector1 + vector2 = " << vector1 + vector2 << "\n";
    std::cout << "vector1 - vector2 = " << vector1 - vector2 << "\n\n";

    std::cout << "Dot(vector1, vector2) = " << math::Dot(vector1, vector2) << "\n";
    std::cout << "Cross(vector1, vector2) = " << math::Cross(vector1, vector2) << "\n\n";

    std::cout << "-4.2f * vector = " << -4.2f * vector << "\n";
    std::cout << "vector * -4.2f = " << vector * -4.2f << "\n";
    std::cout << "vector / 395.98f = " << vector / 395.98f << "\n\n";

    std::cout << "Distance(vector1, vector2) = ";
    std::cout << math::Distance(vector1, vector2) << "\n\n";

    math::Vector3 nullVector1{};
    std::cout << "nullVector1 = " << nullVector1 << "\n";
    
    isNull = nullVector1.IsNull() ? "Yes" : "No";
    std::cout << "Is nullVector1 null? " << isNull << "\n\n";

    math::Vector3 nullVector2(1e-5f, -3.553e-6f, 7.443e-6f);
    std::cout << "nullVector2 = " << nullVector2 << "\n";
    
    isNull = nullVector2.IsNull() ? "Yes" : "No";
    std::cout << "Is nullVector2 null? " << isNull << "\n\n";
}