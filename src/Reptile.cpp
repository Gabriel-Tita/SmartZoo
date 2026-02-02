#include "Reptile.hpp"

/**
 * @brief Constructs a reptile with all attributes.
 */
Reptile::Reptile(const string &speciesName, const string &health, int number, int viewingPlatform,
                 int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
                 bool coldBlooded)
    : Animal(speciesName, health, number, viewingPlatform, maleNumber, femaleNumber, attractiveness,
             enclosureNumber), coldBlooded(coldBlooded) {
}

/** @brief Copy constructor. */
Reptile::Reptile(const Reptile &other) : Animal(other), coldBlooded(other.coldBlooded) {
}

/**
 * @brief Copy assignment operator.
 * @return Reference to *this.
 */
Reptile &Reptile::operator=(const Reptile &other) {
    if (this != &other) {
        Animal::operator=(other);
        coldBlooded = other.coldBlooded;
    }
    return *this;
}

/**
 * @brief Prints basic reptile information.
 */
void Reptile::doPrintInfo() const {
    cout << "Species: " << speciesName << "\n";
    cout << "The Health of the animals: " << health << "\n";
    cout << "The number of animals: " << number << "\n";
    cout << "The number of viewing platforms: " << viewingPlatform << "\n";
    cout << "The number of males: " << maleNumber << "\n";
    cout << "The number of females: " << femaleNumber << "\n";
    cout << "The attractiveness (a number based on how rare this animal is): " << attractiveness << "\n";
    cout << "The number of enclosures in which this creature lives: " << enclosureNumber << "\n";
    cout << "This reptile is " << (coldBlooded ? "" : "not ") << "cold blooded." << "\n";
}

/**
 * @brief Prints detailed reptile information to a stream.
 */
void Reptile::printDetails(ostream &os) const {
    Animal::printDetails(os);
    os << "This reptile is " << (coldBlooded ? "" : "not ") << "cold blooded." << "\n";
}

/** @brief Returns whether the reptile is cold-blooded. */
bool Reptile::isColdBlooded() const {
    return coldBlooded;
}
