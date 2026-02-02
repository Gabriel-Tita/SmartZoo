#include "Animal.hpp"

/**
 * @brief Constructs an Animal using all provided attributes.
 */
Animal::Animal(const string &speciesName, const string &health, int number, int viewingPlatform,
               int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber) {
    this->speciesName = speciesName;
    this->health = health;
    this->number = number;
    this->viewingPlatform = viewingPlatform;
    this->maleNumber = maleNumber;
    this->femaleNumber = femaleNumber;
    this->attractiveness = attractiveness;
    this->enclosureNumber = enclosureNumber;
}

/** @brief Copy constructor. */
Animal::Animal(const Animal &animal) {
    this->speciesName = animal.speciesName;
    this->health = animal.health;
    this->number = animal.number;
    this->viewingPlatform = animal.viewingPlatform;
    this->maleNumber = animal.maleNumber;
    this->femaleNumber = animal.femaleNumber;
    this->attractiveness = animal.attractiveness;
    this->enclosureNumber = animal.enclosureNumber;
}

//operator egal (de atribuire)
/**
 * @brief Copy assignment operator.
 * @return Reference to *this.
 */
Animal &Animal::operator=(const Animal &animal) {
    this->speciesName = animal.speciesName;
    this->health = animal.health;
    this->number = animal.number;
    this->viewingPlatform = animal.viewingPlatform;
    this->maleNumber = animal.maleNumber;
    this->femaleNumber = animal.femaleNumber;
    this->attractiveness = animal.attractiveness;
    this->enclosureNumber = animal.enclosureNumber;
    return *this;
}

/**
 * @brief Prints all stored details about the animal to a stream.
 */
void Animal::printDetails(ostream &os) const {
    os << "Species: " << speciesName << "\n";
    os << "The Health of the animals: " << health << "\n";
    os << "The number of animals: " << number << "\n";
    os << "The number of viewing platforms: " << viewingPlatform << "\n";
    os << "The number of males: " << maleNumber << "\n";
    os << "The number of females: " << femaleNumber << "\n";
    os << "The attractiveness (a number based on how rare this animal is): " << attractiveness << "\n";
    os << "The number of enclosures in which this creature lives: " << enclosureNumber << "\n";
}

/**
 * @brief Stream insertion operator for Animal.
 */
ostream &operator<<(ostream &os, const Animal &animal) {
    os << "This is what we know about the next animal!" << "\n";
    animal.printDetails(os);
    return os;
}

/**
 * @brief Prints basic info by calling the derived implementation.
 */
void Animal::printInfo() const {
    this->doPrintInfo();
}

/** @brief Returns the species name. */
const string &Animal::getSpecies() const {
    return speciesName;
}

/**
 * @brief Increases total number and updates male/female counters.
 * @param gender Gender string (checks for "Male").
 */
void Animal::updateGenderOfCreatures(const string &gender) {
    number++;
    if (gender == "Male") {
        maleNumber++;
    } else {
        femaleNumber++;
    }
}

/**
 * @brief Returns a simple computed value (number * attractiveness).
 */
int Animal::getMoreInfo() const {
    return number * attractiveness;
}
