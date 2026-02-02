#pragma once
#include "Reptile.hpp"

/**
 * @class Snake
 * @brief Represents a snake species.
 *
 * Extends Reptile with information about whether the snake is poisonous.
 */
class Snake : public Reptile {
private:
    /** @brief True if the snake is poisonous. */
    bool isPoisonous = 0;

protected:
    /** @brief Prints snake-specific information. */
    void doPrintInfo() const override;

public:
    /** @brief Default constructor. */
    Snake() = default;

    /**
     * @brief Constructor with all attributes.
     */
    Snake(const string &speciesName, const string &health, int number, int viewingPlatform,
          int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
          bool coldBlooded, bool isPoisonous);

    /** @brief Copy constructor. */
    Snake(const Snake &other);

    /** @brief Copy assignment operator. */
    Snake &operator=(const Snake &other);

    /** @brief Virtual destructor. */
    ~Snake() override = default;

    /** @brief Prints detailed information about the snake. */
    void printDetails(ostream &os) const override;

    /** @brief Makes the snake produce a sound. */
    void makeSound() const override;

    /**
     * @brief Polymorphic copy of the snake.
     * @return Pointer to a cloned object.
     */
    Animal *clone() const override;

    /** @brief Returns whether the snake is poisonous. */
    bool getIsPoisonous() const;

    /** @brief Prints some interesting facts about the snake. */
    void interestingFacts() const;
};
