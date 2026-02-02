#include "Eagle.hpp"
#include "Mammal.hpp"

/**
 * @brief Constructs an eagle with all attributes.
 */
Eagle::Eagle(const string &speciesName, const string &health, int number, int viewingPlatform,
             int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
             bool canFly, double wingspan)
    : Birds(speciesName, health, number, viewingPlatform, maleNumber, femaleNumber, attractiveness,
            enclosureNumber, canFly), wingspan(wingspan) {
}

/** @brief Copy constructor. */
Eagle::Eagle(const Eagle &other) : Birds(other), wingspan(other.wingspan) {
}

/**
 * @brief Copy assignment operator.
 * @return Reference to *this.
 */
Eagle &Eagle::operator=(const Eagle &other) {
    if (this != &other) {
        Birds::operator=(other);
        wingspan = other.wingspan;
    }
    return *this;
}

/**
 * @brief Applies a simple treatment procedure for the eagle.
 */
void Eagle::applyTreatment(std::ostream &os) const {
    os << "Eagle: wing inspection + parasite check.\n";
}

/** @brief Prints the sound made by the eagle. */
void Eagle::makeSound() const {
    cout << "SCREECH" << "\n\n";
}

/**
 * @brief Creates a polymorphic copy of the eagle.
 * @return Pointer to a new Eagle object.
 */
Animal *Eagle::clone() const {
    return new Eagle(*this);
}

/**
 * @brief Prints detailed eagle information to a stream.
 */
void Eagle::printDetails(ostream &os) const {
    Birds::printDetails(os);
    os << "This eagle has a wingspan of " << wingspan << " meters!" << "\n\n";
}

/** @brief Returns the wingspan of the eagle. */
double Eagle::getWingspan() const {
    return wingspan;
}

/**
 * @brief Prints basic eagle information.
 */
void Eagle::doPrintInfo() const {
    Birds::doPrintInfo();
    cout << "This eagle has a wingspan of " << wingspan << " meters!" << "\n";
}

/**
 * @brief Prints an interesting fact about the eagle.
 */
void Eagle::interestingFacts() const {
    if (this->getCanFly() == 1) {
        cout << "This eagle can fly and has a wingspan of " << this->getWingspan() << "!\n";
    }
}
