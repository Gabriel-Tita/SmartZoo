#ifndef OOP_ANIMALFACTORY_HPP
#define OOP_ANIMALFACTORY_HPP
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include "Animal.hpp"
#include "Lion.hpp"
#include "Snake.hpp"
#include "Eagle.hpp"
#include "Crocodile.hpp"

using namespace std;

class AnimalFactory {
    using Creator = function<unique_ptr<Animal>()>;
    unordered_map<string, Creator> creators;

public:
    AnimalFactory();

    unique_ptr<Animal> create(const string& type) const;
};

#endif //OOP_ANIMALFACTORY_HPP
