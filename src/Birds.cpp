#include "Birds.hpp"

Birds::Birds(const string &speciesName, const string &health, int number, int viewingPlatform,
             int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
             bool canFly)
    : Animal(speciesName, health, number, viewingPlatform, maleNumber, femaleNumber, attractiveness,
             enclosureNumber), canFly(canFly) {
}

Birds::Birds(const Birds &other) : Animal(other), canFly(other.canFly) {
}

Birds &Birds::operator=(const Birds &other) {
    if (this != &other) {
        Animal::operator=(other);
        canFly = other.canFly;
    }
    return *this;
}

void Birds::printDetails(ostream &os) const {
    Animal::printDetails(os);
    os << "This bird " << (canFly ? "can " : "can't ") << "fly." << "\n";
}

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

bool Birds::getCanFly() const {
    return canFly;
}
