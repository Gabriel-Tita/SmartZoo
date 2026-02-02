#pragma once
#include "Animal.hpp"

/**
 * @class Reptile
 * @brief Base class for reptile species.
 *
 * Extends Animal with information about whether the reptile is cold-blooded.
 */
class Reptile : public Animal {
private:
    /** @brief True if the reptile is cold-blooded. */
    bool coldBlooded = 0;

protected:
    /** @brief Prints reptile-specific information. */
    void doPrintInfo() const override;

public:
    /** @brief Default constructor. */
    Reptile() = default;

    /**
     * @brief Constructor with all attributes.
     */
    Reptile(const string &speciesName, const string &health, int number, int viewingPlatform,
            int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
            bool coldBlooded);

    /** @brief Copy constructor. */
    Reptile(const Reptile &other);

    /** @brief Copy assignment operator. */
    Reptile &operator=(const Reptile &other);

    /** @brief Virtual destructor. */
    ~Reptile() override = default;

    /**
     * @brief Polymorphic copy (to be implemented by derived classes).
     * @return Pointer to a copy of the most-derived object.
     */
    virtual Animal *clone() const override = 0;

    /** @brief Makes the reptile produce a sound (implemented by derived classes). */
    virtual void makeSound() const override = 0;

    /** @brief Prints detailed information about the reptile. */
    void printDetails(ostream &os) const override;

    /** @brief Returns whether the reptile is cold-blooded. */
    bool isColdBlooded() const;
};
