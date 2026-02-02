#pragma once
#include "Animal.hpp"

/**
 * @class Mammal
 * @brief Base class for mammal species.
 *
 * Extends Animal with information about whether the mammal has fur.
 */
class Mammal : public Animal {
private:
    /** @brief True if the mammal has fur. */
    bool hasFur = 0;

protected:
    /** @brief Prints mammal-specific information. */
    void doPrintInfo() const override;

public:
    /** @brief Default constructor. */
    Mammal() = default;

    /**
     * @brief Constructor with all attributes.
     */
    Mammal(const string &speciesName, const string &health, int number, int viewingPlatform,
           int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
           bool hasFur);

    /** @brief Copy constructor. */
    Mammal(const Mammal &other);

    /** @brief Copy assignment operator. */
    Mammal &operator=(const Mammal &other);

    /** @brief Virtual destructor. */
    ~Mammal() override = default;

    /**
     * @brief Polymorphic copy (to be implemented by derived classes).
     * @return Pointer to a copy of the most-derived object.
     */
    virtual Animal *clone() const override = 0;

    /** @brief Makes the mammal produce a sound (implemented by derived classes). */
    virtual void makeSound() const override = 0;

    /** @brief Prints detailed information about the mammal. */
    void printDetails(ostream &os) const override;

    /** @brief Returns whether the mammal has fur. */
    bool getHasFur() const;

    /**
     * @brief Swaps data between two mammals.
     * @param other Another mammal object.
     */
    void swapp(Mammal &other);
};
