#ifndef OOP_ANIMALFACTORY_HPP
#define OOP_ANIMALFACTORY_HPP
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include "animal.hpp"
#include "lion.hpp"
#include "snake.hpp"
#include "eagle.hpp"
#include "crocodile.hpp"

class AnimalFactory {
    using Creator = std::function<std::unique_ptr<animal>()>;
    std::unordered_map<std::string, Creator> creators;

public:
    AnimalFactory();

    std::unique_ptr<animal> create(const std::string& type) const;
};


#endif //OOP_ANIMALFACTORY_HPP