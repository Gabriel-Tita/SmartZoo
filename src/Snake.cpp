#include "Snake.hpp"

/**
 * @brief Constructs a snake with all attributes.
 */
Snake::Snake(const string &speciesName, const string &health, int number, int viewingPlatform,
             int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
             bool coldBlooded, bool isPoisonous)
    : Reptile(speciesName, health, number, viewingPlatform, maleNumber, femaleNumber, attractiveness,
              enclosureNumber, coldBlooded), isPoisonous(isPoisonous) {
}

/** @brief Copy constructor. */
Snake::Snake(const Snake &other) : Reptile(other), isPoisonous(other.isPoisonous) {
}

/**
 * @brief Copy assignment operator.
 * @return Reference to *this.
 */
Snake &Snake::operator=(const Snake &other) {
    if (this != &other) {
        Reptile::operator=(other);
        isPoisonous = other.isPoisonous;
    }
    return *this;
}

/** @brief Prints the sound made by the snake. */
void Snake::makeSound() const {
    cout << "HISSS" << "\n\n";
}

/**
 * @brief Creates a polymorphic copy of the snake.
 * @return Pointer to a new Snake object.
 */
Animal *Snake::clone() const {
    return new Snake(*this);
}

/**
 * @brief Prints basic snake information.
 */
void Snake::doPrintInfo() const {
    Reptile::doPrintInfo();
    cout << "This snake " << (isPoisonous ? "is " : "isn't ") << "poisonous" << "\n";
}

/**
 * @brief Prints detailed snake information to a stream.
 */
void Snake::printDetails(ostream &os) const {
    Reptile::printDetails(os);
    os << "This snake " << (isPoisonous ? "is " : "isn't ") << "poisonous" << "\n\n";
}

/** @brief Returns whether the snake is poisonous. */
bool Snake::getIsPoisonous() const {
    return isPoisonous;
}

/**
 * @brief Prints an interesting fact about the snake.
 */
void Snake::interestingFacts() const {
    if (this->isColdBlooded() == 1 && this->getIsPoisonous() == 1) {
        cout << "This creature is cold blooded and poisonous!\n";
    }
}
