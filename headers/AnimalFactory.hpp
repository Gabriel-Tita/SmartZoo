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

/**
 * @class AnimalFactory
 * @brief Factory class used to create Animal objects.
 *
 * Uses a map of creators to generate different animal types
 * based on a string key.
 */
class AnimalFactory {
    /** @brief Function type used to create animals. */
    using Creator = function<unique_ptr<Animal>()>;
    /** @brief Map that associates animal types with creator functions. */
    unordered_map<string, Creator> creators;

public:
    /** @brief Constructs the factory and registers all animal types. */
    AnimalFactory();

    /**
     * @brief Creates an animal of the given type.
     * @param type String representing the animal type.
     * @return Unique pointer to the created Animal.
     */
    unique_ptr<Animal> create(const string &type) const;
};

#endif //OOP_ANIMALFACTORY_HPP
