#include "Crocodile.hpp"

/**
 * @brief Constructs a crocodile with all attributes.
 */
Crocodile::Crocodile(const string &speciesName, const string &health, int number, int viewingPlatform,
                     int male_number, int female_number, int attractiveness,
                     int enclosure_number, bool cold_blooded, bool livesInSaltyWaters)
    : Reptile(speciesName, health, number, viewingPlatform, male_number, female_number, attractiveness,
              enclosure_number, cold_blooded), livesInSaltyWaters(livesInSaltyWaters) {
}

/** @brief Copy constructor. */
Crocodile::Crocodile(const Crocodile &other) : Reptile(other), livesInSaltyWaters(other.livesInSaltyWaters) {
}

/**
 * @brief Copy assignment operator.
 * @return Reference to *this.
 */
Crocodile &Crocodile::operator=(const Crocodile &other) {
    if (this != &other) {
        Reptile::operator=(other);
        livesInSaltyWaters = other.livesInSaltyWaters;
    }
    return *this;
}

/** @brief Prints the sound made by the crocodile. */
void Crocodile::makeSound() const {
    cout << "GGRRR-AOH" << "\n\n";
}

/**
 * @brief Creates a polymorphic copy of the crocodile.
 * @return Pointer to a new Crocodile object.
 */
Animal *Crocodile::clone() const {
    return new Crocodile(*this);
}

/**
 * @brief Prints basic crocodile information.
 */
void Crocodile::doPrintInfo() const {
    Reptile::doPrintInfo();
    cout << "This crocodile lives in " << (livesInSaltyWaters ? "salty " : "sweet ") << "waters" << "\n";
}

/**
 * @brief Prints detailed crocodile information to a stream.
 */
void Crocodile::printDetails(ostream &os) const {
    Reptile::printDetails(os);
    os << "This crocodile lives in " << (livesInSaltyWaters ? "salty " : "sweet ") << "waters" << "\n\n";
}

/** @brief Returns whether the crocodile lives in salty waters. */
bool Crocodile::getLivesInSaltyWaters() const {
    return livesInSaltyWaters;
}

/**
 * @brief Prints an interesting fact about the crocodile.
 */
void Crocodile::interestingFacts() const {
    if (this->isColdBlooded() == 1 && this->getLivesInSaltyWaters() == 1) {
        cout << "This creature is cold blooded and lives in salty waters!\n";
    }
}
