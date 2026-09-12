#include <Foo.hpp>
#include <Math/Vector3.hpp>

#include <iostream>

int main()
{
    Math::Vector3 vector0{1.0f, 2.34f, -8.553f};

    std::cout << "vector0.x = " << vector0.x << "\n";
    std::cout << "vector0.y = " << vector0.y << "\n";
    std::cout << "vector0.z = " << vector0.z << "\n\n";

    std::cout << "vector0[0] = " << vector0[0] << "\n";
    std::cout << "vector0[1] = " << vector0[1] << "\n";
    std::cout << "vector0[2] = " << vector0[2] << "\n\n";

    auto isNull{vector0.IsNull() ? "Yes" : "No"};
    std::cout << "Is vector0 null? " << isNull << "\n\n";

    Math::Vector3 vector1{98.3332f, -22.3432f, 399.3029f};
    Math::Vector3 vector2{-33.3554f, 885.03f, -135.44f};

    std::cout << "vector1 + vector2 = " << vector1 + vector2 << "\n";
    std::cout << "vector1 - vector2 = " << vector1 - vector2 << "\n\n";

    std::cout << "vector1 * vector2 = " << vector1 * vector2 << "\n";
    std::cout << "vector1 ^ vector2 = " << (vector1 ^ vector2) << "\n\n";

    std::cout << "-4.2f * vector0 = " << -4.2f * vector0 << "\n";
    std::cout << "vector0 * -4.2f = " << vector0 * -4.2f << "\n";
    std::cout << "vector0 / 395.98f = " << vector0 / 395.98f << "\n\n";

    std::cout << "Distance(vector1, vector2) = ";
    std::cout << Math::Distance(vector1, vector2) << "\n\n";

    Math::Vector3 nullVector1{0.0f, 0.0f, 0.0f};
    std::cout << "nullVector1 = " << nullVector1 << "\n";
    
    isNull = nullVector1.IsNull() ? "Yes" : "No";
    std::cout << "Is nullVector1 null? " << isNull << "\n\n";

    Math::Vector3 nullVector2{1e-5f, -3.553e-6f, 7.443e-6f};
    std::cout << "nullVector2 = " << nullVector2 << "\n";
    
    isNull = nullVector2.IsNull() ? "Yes" : "No";
    std::cout << "Is nullVector2 null? " << isNull << "\n\n";

    std::cout << "k_fooConstant = " << k_fooConstant << "\n\n";

    std::cout << "g_fooGlobalVariable = " << g_fooGlobalVariable << "\n";

    g_fooGlobalVariable += 1;
    std::cout << "After 1 has been added to g_fooGlobalVariable:\n";
    std::cout << "g_fooGlobalVariable = " << g_fooGlobalVariable << "\n\n";

    auto dog{MakeUniqueDog("Bob", 4)};
    auto cat{MakeSharedCat("Alice", 7)};

    std::cout << WhatDoesItSay(*dog) << "\n";
    std::cout << WhatDoesItSay(*cat) << "\n\n";

    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Sum of first ten integers is: " << Sum(numbers) << "\n\n";

    // GuessTheNumber();
}