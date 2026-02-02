#include "Lion.hpp"
#include <algorithm>

/**
 * @brief Constructs a lion with all attributes.
 */
Lion::Lion(const string &speciesName, const string &health, int number, int viewingPlatform,
           int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
           bool has_fur, const string &maneColour)
    : Mammal(speciesName, health, number, viewingPlatform, maleNumber, femaleNumber, attractiveness,
             enclosureNumber, has_fur), maneColour(maneColour) {
}

/** @brief Copy constructor. */
Lion::Lion(const Lion &other) : Mammal(other), maneColour(other.maneColour) {
}

/**
 * @brief Copy assignment operator.
 * @return Reference to *this.
 */
Lion &Lion::operator=(const Lion &other) {
    if (this != &other) {
        maneColour = other.maneColour;
        Mammal::operator=(other);
    }
    return *this;
}

/** @brief Prints the sound made by the lion. */
void Lion::makeSound() const {
    cout << "ROAR" << "\n\n";
}

/**
 * @brief Applies a simple treatment procedure for the lion.
 */
void Lion::applyTreatment(ostream& os) const{
    os << "Lion: vaccination + health check.\n";
}

/**
 * @brief Creates a polymorphic copy of the lion.
 * @return Pointer to a new Lion object.
 */
Animal *Lion::clone() const {
    return new Lion(*this);
}

/**
 * @brief Prints detailed lion information to a stream.
 */
void Lion::printDetails(ostream &os) const {
    Mammal::printDetails(os);
    os << "Mane colour: " << maneColour << "\n\n";
}

/**
 * @brief Prints basic lion information.
 */
void Lion::doPrintInfo() const {
    Mammal::doPrintInfo();
    cout << "Mane colour: " << maneColour << "\n";
}

/** @brief Returns the lion's mane colour. */
const string &Lion::getManeColour() const {
    return maneColour;
}

/**
 * @brief Prints an interesting fact about the lion.
 */
void Lion::interestingFacts() const {
    if (this->getHasFur() == 1) {
        cout << "This creature has fur and a mane of colour " << this->getManeColour() << "!\n";
    }
}

/**
 * @brief Swaps data between two lions.
 */
void Lion::swapp(Lion &other) {
    swap(maneColour, other.maneColour);
    Mammal::swapp(other);
}
