#pragma once
#include <iostream>
#include "Enclosure.hpp"
#include "Zoo.hpp"
using namespace std;

/**
 * @class ListOfEnclosures
 * @brief Stores and manages all enclosures in the zoo.
 *
 * Keeps a list of Enclosure objects and allows adding animals
 * to available enclosures.
 */
class ListOfEnclosures {
private:
    // clasa care retine cate tarcuri avem pentru fiecare specie
    /** @brief Total number of enclosures. */
    static int number;
    /** @brief Vector of all enclosures. */
    vector<Enclosure> enc;

public:
    /** @brief Default constructor. */
    ListOfEnclosures() = default;

    /** @brief Destructor. */
    ~ListOfEnclosures() = default;

    /** @brief Returns the total number of enclosures. */
    static int getNumberOfEnclosures();

    /**
     * @brief Returns the species name of a given enclosure.
     * @param num Index of the enclosure.
     */
    const string &getEnclosureSpecies(int num) const;

    /**
     * @brief Adds a new enclosure to the list.
     */
    void add(const Enclosure &Enclosure);

    /**
     * @brief Tries to add an animal to a suitable enclosure.
     * @param species Zoo where the animal is added.
     * @param name Species name.
     * @param gender Gender of the animal.
     */
    void queryAddAnimal(Zoo &species, const string &name, const string &gender);

    /** @brief Prints information about all enclosures. */
    void printInfo() const;

    /** @brief Output operator for printing all enclosures. */
    friend ostream &operator<<(ostream &os, const ListOfEnclosures &listOfEnclosures);
};
