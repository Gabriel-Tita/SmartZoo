#pragma once
#include <string>
#include <iostream>
using namespace std;

/**
 * @class Enclosure
 * @brief Represents the enclosure information for a species.
 *
 * Stores data about how many animals can live together and
 * how many enclosures exist for a certain species.
 */
class Enclosure {
private:
    /** @brief Species name and enclosure-related counters. */
    string species = "Unknown";
    int numberOfAnimals = -1, numberOfEnclosures = -1, currentAnimalNumber = -1;

public:
    /** @brief Default constructor. */
    Enclosure() = default;

    /**
     * @brief Constructor with all attributes.
     */
    Enclosure(const string &species, int numberOfAnimals, int numberOfEnclosures,
              int currentAnimalNumber);

    /** @brief Destructor. */
    ~Enclosure() = default;

    /** @brief Returns the species name. */
    const string &getSpecies() const;

    /** @brief Returns the maximum number of animals per enclosure. */
    int getNumberOfAnimals() const;

    /** @brief Returns the current number of animals in the enclosure. */
    int getCurrentAnimalsNumber() const;

    /** @brief Prints enclosure information to standard output. */
    void printInfo() const;

    /** @brief Output operator for printing an enclosure. */
    friend ostream &operator<<(ostream &os, const Enclosure &enclosure);

    /** @brief Increases the current number of animals by one. */
    void addOneAnimal();
};
