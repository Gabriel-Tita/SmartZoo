#include "Lion.hpp"
#include <algorithm>

Lion::Lion(const string &speciesName, const string &health, int number, int viewingPlatform,
           int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
           bool has_fur, const string &maneColour)
    : Mammal(speciesName, health, number, viewingPlatform, maleNumber, femaleNumber, attractiveness,
             enclosureNumber, has_fur), maneColour(maneColour) {
}

Lion::Lion(const Lion &other) : Mammal(other), maneColour(other.maneColour) {
}

Lion &Lion::operator=(const Lion &other) {
    if (this != &other) {
        maneColour = other.maneColour;
        Mammal::operator=(other);
    }
    return *this;
}

void Lion::makeSound() const {
    cout << "ROAR" << "\n\n";
}

void Lion::applyTreatment(ostream& os) const{
    os << "Lion: vaccination + health check.\n";
}

Animal *Lion::clone() const {
    return new Lion(*this);
}

void Lion::printDetails(ostream &os) const {
    Mammal::printDetails(os);
    os << "Mane colour: " << maneColour << "\n\n";
}

void Lion::doPrintInfo() const {
    Mammal::doPrintInfo();
    cout << "Mane colour: " << maneColour << "\n";
}

const string &Lion::getManeColour() const {
    return maneColour;
}

void Lion::interestingFacts() const {
    if (this->getHasFur() == 1) {
        cout << "This creature has fur and a mane of colour " << this->getManeColour() << "!\n";
    }
}

void Lion::swapp(Lion &other) {
    swap(maneColour, other.maneColour);
    Mammal::swapp(other);
}
