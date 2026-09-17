#include "foo/foo.hpp"
#include <iostream>
#include <sstream>

namespace foo {

std::string WhatDoesItSay(const Animal& animal) {
    std::ostringstream outputStringStream;
    outputStringStream << animal.GetName() << " says " <<  animal.Sound();
    return outputStringStream.str();
}

std::unique_ptr<Animal> CreateUniqueDog(std::string_view name, std::uint8_t age) {
    return std::make_unique<Dog>(name, age);
}

std::shared_ptr<Animal> CreateSharedCat(std::string_view name, std::uint8_t age) {
    return std::make_shared<Cat>(name, age);
}

} // namespace foo