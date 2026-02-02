#pragma once
#include "Animal.hpp"
#include "Treatment.hpp"

/**
 * @class Birds
 * @brief Base class for bird species.
 *
 * Extends Animal with a simple property that tells if the bird can fly.
 */
class Birds : public Animal {
private:
    /** @brief True if the bird can fly. */
    bool canFly = 0;

protected:
    /** @brief Prints bird information (used by printInfo()). */
    void doPrintInfo() const override;

public:
    /** @brief Default constructor. */
    Birds() = default;

    /**
     * @brief Constructor with attributes, including flight ability.
     */
    Birds(const string &speciesName, const string &health, int number, int viewingPlatform,
          int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
          bool canFly);

    /** @brief Copy constructor. */
    Birds(const Birds &other);

    /** @brief Copy assignment operator. */
    Birds &operator=(const Birds &other);

    /** @brief Virtual destructor. */
    ~Birds() override = default;

    /**
     * @brief Polymorphic copy (to be implemented by derived bird classes).
     * @return Pointer to a copy of the most-derived object.
     */
    virtual Animal *clone() const override = 0;

    /** @brief Makes the bird produce a sound (implemented by derived classes). */
    virtual void makeSound() const override = 0;

    /** @brief Prints details, including whether it can fly. */
    void printDetails(ostream &os) const override;

    /** @brief Returns whether the bird can fly. */
    bool getCanFly() const;
};
