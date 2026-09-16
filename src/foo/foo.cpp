#include <foo/foo.hpp>

#include <iostream>
#include <sstream>

namespace foo {

std::string ToString(GreekLetter letter) 
{
    switch(letter)
    {
    case GreekLetter::Alpha:
        return "Alpha";

    case GreekLetter::Beta:
        return "Beta";

    case GreekLetter::Gamma:
        return "Gamma";

    case GreekLetter::Delta:
        return "Delta";

    default:
        return "Unknown";
    }
}

std::string WhatDoesItSay(const Animal& animal)
{
    std::ostringstream outputStringStream;
    outputStringStream << animal.Name() << " says " <<  animal.Sound();
    return outputStringStream.str();
}

std::unique_ptr<Animal> MakeUniqueDog(std::string_view name, std::uint8_t age)
{
    return std::make_unique<Dog>(name, age);
}

std::shared_ptr<Animal> MakeSharedCat(std::string_view name, std::uint8_t age)
{
    return std::make_shared<Cat>(name, age);
}

void GuessTheNumber()
{
    std::cout << "You are playing \"Guess The Number\".\n\n";

    while (true)
    {
        std::cout << "Insert a number between 1 and 100, -1 or any other ";
        std::cout << "negative number to quit: ";

        std::int16_t input;
        std::cin >> input;

        if (input < 0)
        {   
            std::cout << "Quitting the game. Thank you for playing!\n\n";
            return;
        }

        if (input == 100)
        {
            std::cout << "Correct! You won!\n\n";
            return;
        }

        if (input < 1 || input > 100) 
        {
            std::cout << "Your number is out of range!";
        }
        else if (input < 40)
        {
            std::cout << "Cold.";
        }
        else if (input < 70)
        {
            std::cout << "Warm.";
        }
        else 
        {
            std::cout << "Hot.";
        }

        std::cout << " Please retry.\n\n";
    }
}

} // namespace foo