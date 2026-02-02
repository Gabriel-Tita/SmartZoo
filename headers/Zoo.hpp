#pragma once
#include <vector>
#include <iostream>
#include "Animal.hpp"
#include <memory>
using namespace std;

/**
 * @class Zoo
 * @brief Manages a collection of animals in the zoo.
 *
 * Stores animals as unique_ptr and provides basic operations like adding animals,
 * simulating a day, and running treatments.
 */
class Zoo {
private:
    /** @brief List of animal families stored as polymorphic objects. */
    vector<unique_ptr<Animal> > animals;
    /** @brief Number of animal families currently stored. */
    static int numberOfFamiliesOfAnimals;

public:
    /** @brief Returns the number of animal families. */
    static int getNumberOfFamilies();

    /** @brief Default constructor. */
    Zoo() = default;

    /** @brief Destructor. */
    ~Zoo() = default;

    /** @brief Output operator for printing a short list of animals. */
    friend ostream &operator<<(ostream &os, const Zoo &zoo);

    /** @brief Prints detailed information about all animals. */
    void printInfo() const;

    /**
     * @brief Runs treatments for animals that support the Treatment interface.
     * @param os Output stream used to print the treatment steps.
     */
    void veterinaryDay(std::ostream &os);

    /**
     * @brief Adds a new animal family using cloning (Prototype).
     * @param animal Animal to copy into the zoo.
     */
    void add(const Animal &animal);

    /**
     * @brief Adds one individual to an existing species (updates gender counters).
     * @param name Species name.
     * @param gender Gender string ("Male" / "Female").
     */
    void addIndividual(const string &name, const string &gender);

    /**
     * @brief Returns an integer info value for a given species.
     * @param name Species name.
     * @return Value returned by the matching animal, or 0 if not found.
     */
    int getInfo(const string &name) const;

    /**
     * @brief Simulates a day in the zoo (sounds + veterinary day).
     * @param os Output stream used to print messages.
     */
    void simulateDay(std::ostream &os);

    /** @brief Prints info and makes each animal produce its sound. */
    void dailyFeedAndSound() const;
};
