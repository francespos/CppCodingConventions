#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace foo {

// This is an extended comment. Bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla bla
// bla bla.
constexpr double k_fooConstant = 43.3853287582033572947; // this is an inline comment

// Short comment
inline std::uint32_t g_fooGlobalVariable = 33934357; 

enum class GreekLetter : std::uint8_t { k_alpha, k_beta, k_gamma, k_delta };

class Animal {
public:
    Animal(std::string_view name, std::uint8_t age)
        : m_name(name), m_age(age) {}

    virtual ~Animal() = default;

    virtual std::string GetName() const { return m_name; }
    virtual void SetName(std::string_view name) { m_name = name; }

    virtual std::uint8_t GetAge() const { return m_age; }
    virtual void SetAge(std::uint8_t age) { m_age = age; }

    virtual std::string Sound() const = 0;

protected:
    std::string m_name;
    std::uint8_t m_age;
};

class Dog : public Animal {
public:
    Dog(std::string_view name, std::uint8_t age)
        : Animal{name, age} {}

    virtual std::string Sound() const override { return "Woof!"; }
};

class Cat : public Animal {
public:
    Cat(std::string_view name, std::uint8_t age)
        : Animal{name, age} {}

    virtual std::string Sound() const override { return "Meow!"; }
};

std::string WhatDoesItSay(const Animal& animal);

std::unique_ptr<Animal> CreateUniqueDog(std::string_view name, std::uint8_t age);
std::shared_ptr<Animal> CreateSharedCat(std::string_view name, std::uint8_t age);

} // namespace foo