#pragma once

#include <cstdint>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>


// This is an extended comment. Bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla
// bla bla.
constexpr double k_fooConstant{43.3853287582033572947}; // This is an inline comment

inline std::uint32_t g_fooGlobalVariable{33934357}; 

enum class GreekLetter : std::uint8_t
{
    Alpha, 
    Beta, 
    Gamma, 
    Delta
};

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

constexpr bool IsEven(int x) 
{
    return (x % 2 == 0) ? true : false;
}

class Animal 
{
public:
    Animal(std::string_view name, std::uint8_t age)
        : m_name{name}, m_age{age}
    {
    }

    virtual std::string Name() const 
    {
        return m_name;
    }

    virtual void SetName(std::string_view name) 
    {
        m_name = name;
    }

    virtual std::uint8_t Age() const
    {
        return m_age;
    }

    virtual void SetAge(std::uint8_t age)
    {
        m_age = age;
    }

    virtual std::string Sound() const = 0;

protected:
    std::string m_name;
    std::uint8_t m_age;
};

class Dog : public Animal
{
public:
    Dog(std::string_view name, std::uint8_t age)
        : Animal{name, age}
    {
    }

    virtual std::string Sound() const override
    {
        return "Woof!";
    }
};

class Cat : public Animal
{
public:
    Cat(std::string_view name, std::uint8_t age)
        : Animal{name, age}
    {
    }

    virtual std::string Sound() const override
    {
        return "Meow!";
    }
};

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

template <typename T>
T Sum(const std::vector<T>& numbers)
{
    T result{};

    for (const auto& number : numbers)
    {
        result += number;
    }

    return result;
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