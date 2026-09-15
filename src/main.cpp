#include <foo/foo.hpp>
#include <math/Vector3d.hpp>

#include <iostream>

int main()
{
    math::Vector3d vector{1.0f, 2.34f, -8.553f};

    std::cout << "vector.x = " << vector.x << "\n";
    std::cout << "vector.y = " << vector.y << "\n";
    std::cout << "vector.z = " << vector.z << "\n\n";

    std::cout << "vector[0] = " << vector[0] << "\n";
    std::cout << "vector[1] = " << vector[1] << "\n";
    std::cout << "vector[2] = " << vector[2] << "\n\n";

    auto isNull{vector.IsNull() ? "Yes" : "No"};
    std::cout << "Is vector null? " << isNull << "\n\n";

    math::Vector3d vector1{98.3332f, -22.3432f, 399.3029f};
    math::Vector3d vector2{-33.3554f, 885.03f, -135.44f};

    std::cout << "vector1 + vector2 = " << vector1 + vector2 << "\n";
    std::cout << "vector1 - vector2 = " << vector1 - vector2 << "\n\n";

    std::cout << "Dot(vector1, vector2) = " << math::Dot(vector1, vector2) << "\n";
    std::cout << "Cross(vector1, vector2) = " << math::Cross(vector1, vector2) << "\n\n";

    std::cout << "-4.2f * vector = " << -4.2f * vector << "\n";
    std::cout << "vector * -4.2f = " << vector * -4.2f << "\n";
    std::cout << "vector / 395.98f = " << vector / 395.98f << "\n\n";

    std::cout << "Distance(vector1, vector2) = ";
    std::cout << math::Distance(vector1, vector2) << "\n\n";

    math::Vector3d nullVector1{0.0f, 0.0f, 0.0f};
    std::cout << "nullVector1 = " << nullVector1 << "\n";
    
    isNull = nullVector1.IsNull() ? "Yes" : "No";
    std::cout << "Is nullVector1 null? " << isNull << "\n\n";

    math::Vector3d nullVector2{1e-5f, -3.553e-6f, 7.443e-6f};
    std::cout << "nullVector2 = " << nullVector2 << "\n";
    
    isNull = nullVector2.IsNull() ? "Yes" : "No";
    std::cout << "Is nullVector2 null? " << isNull << "\n\n";

    std::cout << "k_fooConstant = " << foo::k_fooConstant << "\n\n";

    std::cout << "g_fooGlobalVariable = " << foo::g_fooGlobalVariable << "\n";

    foo::g_fooGlobalVariable += 1;
    std::cout << "After 1 has been added to g_fooGlobalVariable:\n";
    std::cout << "g_fooGlobalVariable = " << foo::g_fooGlobalVariable << "\n\n";

    auto dog{foo::MakeUniqueDog("Bob", 4)};
    auto cat{foo::MakeSharedCat("Alice", 7)};

    std::cout << foo::WhatDoesItSay(*dog) << "\n";
    std::cout << foo::WhatDoesItSay(*cat) << "\n\n";

    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Sum of first ten integers is: " << foo::Sum(numbers) << "\n\n";

    // GuessTheNumber();
}