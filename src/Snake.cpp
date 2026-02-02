#include "Snake.hpp"

Snake::Snake(const string &speciesName, const string &health, int number, int viewingPlatform,
             int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
             bool coldBlooded, bool isPoisonous)
    : Reptile(speciesName, health, number, viewingPlatform, maleNumber, femaleNumber, attractiveness,
              enclosureNumber, coldBlooded), isPoisonous(isPoisonous) {
}

Snake::Snake(const Snake &other) : Reptile(other), isPoisonous(other.isPoisonous) {
}

Snake &Snake::operator=(const Snake &other) {
    if (this != &other) {
        Reptile::operator=(other);
        isPoisonous = other.isPoisonous;
    }
    return *this;
}

void Snake::makeSound() const {
    cout << "HISSS" << "\n\n";
}

Animal *Snake::clone() const {
    return new Snake(*this);
}

void Snake::doPrintInfo() const {
    Reptile::doPrintInfo();
    cout << "This snake " << (isPoisonous ? "is " : "isn't ") << "poisonous" << "\n";
}

void Snake::printDetails(ostream &os) const {
    Reptile::printDetails(os);
    os << "This snake " << (isPoisonous ? "is " : "isn't ") << "poisonous" << "\n\n";
}

bool Snake::getIsPoisonous() const {
    return isPoisonous;
}

void Snake::interestingFacts() const {
    if (this->isColdBlooded() == 1 && this->getIsPoisonous() == 1) {
        cout << "This creature is cold blooded and poisonous!\n";
    }
}
