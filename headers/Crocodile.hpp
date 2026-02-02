#pragma once
#include "Reptile.hpp"

/**
 * @class Crocodile
 * @brief Represents a crocodile species.
 *
 * Extends Reptile with information about the type of water it lives in.
 */
class Crocodile : public Reptile {
private:
    /** @brief True if the crocodile lives in salty waters. */
    bool livesInSaltyWaters = 0;

protected:
    /** @brief Prints crocodile-specific information. */
    void doPrintInfo() const override;

public:
    /** @brief Default constructor. */
    Crocodile() = default;

    /**
     * @brief Constructor with all attributes.
     */
    Crocodile(const string &speciesName, const string &health, int number, int viewingPlatform,
              int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
              bool coldBlooded, bool livesInSaltyWaters);

    /** @brief Copy constructor. */
    Crocodile(const Crocodile &other);

    /** @brief Copy assignment operator. */
    Crocodile &operator=(const Crocodile &other);

    /** @brief Virtual destructor. */
    ~Crocodile() override = default;

    /** @brief Prints detailed information about the crocodile. */
    void printDetails(ostream &os) const override;

    /** @brief Makes the crocodile produce a sound. */
    void makeSound() const override;

    /**
     * @brief Polymorphic copy of the crocodile.
     * @return Pointer to a cloned object.
     */
    Animal *clone() const override;

    /** @brief Returns whether the crocodile lives in salty waters. */
    bool getLivesInSaltyWaters() const;

    /** @brief Prints some interesting facts about the crocodile. */
    void interestingFacts() const;
};
