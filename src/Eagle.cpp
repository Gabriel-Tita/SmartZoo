#include "Eagle.hpp"
#include "Mammal.hpp"

Eagle::Eagle(const string &speciesName, const string &health, int number, int viewingPlatform,
             int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
             bool canFly, double wingspan)
    : Birds(speciesName, health, number, viewingPlatform, maleNumber, femaleNumber, attractiveness,
            enclosureNumber, canFly), wingspan(wingspan) {
}

Eagle::Eagle(const Eagle &other) : Birds(other), wingspan(other.wingspan) {
}

Eagle &Eagle::operator=(const Eagle &other) {
    if (this != &other) {
        Birds::operator=(other);
        wingspan = other.wingspan;
    }
    return *this;
}

void Eagle::applyTreatment(std::ostream& os) const {
    os << "Eagle: wing inspection + parasite check.\n";
}

void Eagle::makeSound() const {
    cout << "SCREECH" << "\n\n";
}

Animal *Eagle::clone() const {
    return new Eagle(*this);
}

void Eagle::printDetails(ostream &os) const {
    Birds::printDetails(os);
    os << "This eagle has a wingspan of " << wingspan << " meters!" << "\n\n";
}

double Eagle::getWingspan() const {
    return wingspan;
}

void Eagle::doPrintInfo() const {
    Birds::doPrintInfo();
    cout << "This eagle has a wingspan of " << wingspan << " meters!" << "\n";
}

void Eagle::interestingFacts() const {
    if (this->getCanFly() == 1) {
        cout << "This eagle can fly and has a wingspan of " << this->getWingspan() << "!\n";
    }
}
