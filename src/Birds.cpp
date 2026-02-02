#include "Birds.hpp"

/**
 * @brief Constructs a bird with all base Animal attributes and flight ability.
 */
Birds::Birds(const string &speciesName, const string &health, int number, int viewingPlatform,
             int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
             bool canFly)
    : Animal(speciesName, health, number, viewingPlatform, maleNumber, femaleNumber, attractiveness,
             enclosureNumber), canFly(canFly) {
}

/** @brief Copy constructor. */
Birds::Birds(const Birds &other) : Animal(other), canFly(other.canFly) {
}

/**
 * @brief Copy assignment operator.
 * @return Reference to *this.
 */
Birds &Birds::operator=(const Birds &other) {
    if (this != &other) {
        Animal::operator=(other);
        canFly = other.canFly;
    }
    return *this;
}

/**
 * @brief Prints Animal details and adds flight information.
 */
void Birds::printDetails(ostream &os) const {
    Animal::printDetails(os);
    os << "This bird " << (canFly ? "can " : "can't ") << "fly." << "\n";
}

/**
 * @brief Prints basic bird information (used by printInfo()).
 */
void Birds::doPrintInfo() const {
    cout << "Species: " << speciesName << "\n";
    cout << "The Health of the animals: " << health << "\n";
    cout << "The number of animals: " << number << "\n";
    cout << "The number of viewing platforms: " << viewingPlatform << "\n";
    cout << "The number of males: " << maleNumber << "\n";
    cout << "The number of females: " << femaleNumber << "\n";
    cout << "The attractiveness (a number based on how rare this animal is): " << attractiveness << "\n";
    cout << "The number of enclosures in which this creature lives: " << enclosureNumber << "\n";
    cout << "This bird " << (canFly ? "can " : "can't ") << "fly." << "\n";
}

/** @brief Returns whether the bird can fly. */
bool Birds::getCanFly() const {
    return canFly;
}
