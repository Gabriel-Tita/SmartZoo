#include "Mammal.hpp"
#include <algorithm>

/**
 * @brief Constructs a mammal with all attributes.
 */
Mammal::Mammal(const string &speciesName, const string &health, int number, int viewingPlatform,
               int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
               bool hasFur)
    : Animal(speciesName, health, number, viewingPlatform, maleNumber, femaleNumber,
             attractiveness, enclosureNumber), hasFur(hasFur) {
}

/** @brief Copy constructor. */
Mammal::Mammal(const Mammal &other) : Animal(other), hasFur(other.hasFur) {
}

/**
 * @brief Copy assignment operator.
 * @return Reference to *this.
 */
Mammal &Mammal::operator=(const Mammal &other) {
    if (this != &other) {
        Animal::operator=(other);
        hasFur = other.hasFur;
    }
    return *this;
}

/**
 * @brief Prints basic mammal information.
 */
void Mammal::doPrintInfo() const {
    cout << "Species: " << speciesName << "\n";
    cout << "The Health of the animals: " << health << "\n";
    cout << "The number of animals: " << number << "\n";
    cout << "The number of viewing platforms: " << viewingPlatform << "\n";
    cout << "The number of males: " << maleNumber << "\n";
    cout << "The number of females: " << femaleNumber << "\n";
    cout << "The attractiveness (a number based on how rare this animal is): " << attractiveness << "\n";
    cout << "The number of enclosures in which this creature lives: " << enclosureNumber << "\n";
    cout << "This Mammal " << (hasFur ? "has fur." : "has no fur.") << "\n";
}

/**
 * @brief Prints detailed mammal information to a stream.
 */
void Mammal::printDetails(ostream &os) const {
    Animal::printDetails(os);
    os << "This Mammal " << (hasFur ? "has fur." : "has no fur.") << "\n";
}

/** @brief Returns whether the mammal has fur. */
bool Mammal::getHasFur() const {
    return hasFur;
}

/**
 * @brief Swaps all data between two mammals.
 */
void Mammal::swapp(Mammal &other) {
    swap(hasFur, other.hasFur);
    swap(speciesName, other.speciesName);
    swap(health, other.health);
    swap(number, other.number);
    swap(viewingPlatform, other.viewingPlatform);
    swap(maleNumber, other.maleNumber);
    swap(femaleNumber, other.femaleNumber);
    swap(attractiveness, other.attractiveness);
    swap(enclosureNumber, other.enclosureNumber);
}
