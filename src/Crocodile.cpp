#include "Crocodile.hpp"

Crocodile::Crocodile(const string &speciesName, const string &health, int number, int viewingPlatform,
                     int male_number, int female_number, int attractiveness,
                     int enclosure_number, bool cold_blooded, bool livesInSaltyWaters)
    : Reptile(speciesName, health, number, viewingPlatform, male_number, female_number, attractiveness,
              enclosure_number, cold_blooded), livesInSaltyWaters(livesInSaltyWaters) {
}

Crocodile::Crocodile(const Crocodile &other) : Reptile(other), livesInSaltyWaters(other.livesInSaltyWaters) {
}

Crocodile &Crocodile::operator=(const Crocodile &other) {
    if (this != &other) {
        Reptile::operator=(other);
        livesInSaltyWaters = other.livesInSaltyWaters;
    }
    return *this;
}

void Crocodile::makeSound() const {
    cout << "GGRRR-AOH" << "\n\n";
}

Animal *Crocodile::clone() const {
    return new Crocodile(*this);
}

void Crocodile::doPrintInfo() const {
    Reptile::doPrintInfo();
    cout << "This crocodile lives in " << (livesInSaltyWaters ? "salty " : "sweet ") << "waters" << "\n";
}

void Crocodile::printDetails(ostream &os) const {
    Reptile::printDetails(os);
    os << "This crocodile lives in " << (livesInSaltyWaters ? "salty " : "sweet ") << "waters" << "\n\n";
}

bool Crocodile::getLivesInSaltyWaters() const {
    return livesInSaltyWaters;
}

void Crocodile::interestingFacts() const {
    if (this->isColdBlooded() == 1 && this->getLivesInSaltyWaters() == 1) {
        cout << "This creature is cold blooded and lives in salty waters!\n";
    }
}
