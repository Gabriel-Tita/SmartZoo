#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @class Animal
 * @brief Abstract base class for animal species in the park.
 *
 * Stores basic information about a species and defines a common interface
 * for derived animal types.
 */
class Animal {
    //clasa care retine informatii despre fiecare specie din parc
protected:
    /** @brief Species name and health status. */
    string speciesName = "Unknown", health = "Unknown";
    /** @brief Stored numeric information about the species (counts, location, etc.). */
    int number = -1, viewingPlatform = -1, maleNumber = -1, femaleNumber = -1, attractiveness = -1, enclosureNumber
                    = -1;

    /** @brief Helper used by printInfo() to print derived-specific information. */
    virtual void doPrintInfo() const = 0;

public:
    /** @brief Default constructor. */
    Animal() = default;

    /**
     * @brief Constructor with all attributes.
     */
    Animal(const string &speciesName, const string &health, int number, int viewingPlatform,
           int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber);

    /** @brief Copy constructor. */
    //contructor de copiere
    Animal(const Animal &animal);

    /** @brief Copy assignment operator. */
    //operator egal (de atribuire)
    Animal &operator=(const Animal &animal);

    /** @brief Virtual destructor. */
    virtual ~Animal() = default;

    /**
     * @brief Polymorphic copy (Prototype pattern).
     * @return Pointer to a copy of the most-derived object.
     */
    // Prototype pattern: polymorphic copy (virtual constructor)
    virtual Animal *clone() const = 0;

    /** @brief Makes the animal produce a sound (implemented by derived classes). */
    virtual void makeSound() const = 0;

    /** @brief Prints detailed information to a stream. */
    virtual void printDetails(ostream &os) const;

    /** @brief Prints an animal using a stream. */
    friend ostream &operator<<(ostream &os, const Animal &animal);

    /** @brief Prints basic information (calls doPrintInfo()). */
    virtual void printInfo() const;

    /** @brief Returns the species name. */
    const string &getSpecies() const;

    /**
     * @brief Updates total and gender-specific counts.
     * @param gender Gender string (e.g. "Male").
     */
    void updateGenderOfCreatures(const string &gender);

    /** @brief Returns a computed value used for "more info". */
    int getMoreInfo() const;
};
