#include "Enclosure.hpp"
// clasa care retine informatii despre tarcurile fiecarei specii

Enclosure::Enclosure(const string &species, int numberOfAnimals, int numberOfEnclosures,
                     int currentAnimalNumber) {
    this->species = species;
    this->numberOfAnimals = numberOfAnimals;
    this->numberOfEnclosures = numberOfEnclosures;
    this->currentAnimalNumber = currentAnimalNumber;
}

const string &Enclosure::getSpecies() const {
    return species;
}

int Enclosure::getNumberOfAnimals() const {
    return numberOfAnimals;
}

int Enclosure::getCurrentAnimalsNumber() const {
    return currentAnimalNumber;
}

void Enclosure::printInfo() const {
    cout << "This is everything about the enclosures of the ";
    cout << species << "!\n";
    cout << "The number of animals that can coexist in one single enclosure: " << numberOfAnimals << "\n";
    cout << "The number of enclosures for this species that we currently have: " << numberOfEnclosures << "\n";
    cout << "The number of animals that are right now in the enclosure: " << currentAnimalNumber << "\n\n";
}

ostream &operator<<(ostream &os, const Enclosure &enclosure) {
    os << "This is everything about the enclosures of the ";
    os << enclosure.species << "!\n";
    os << "The number of animals that can coexist in one single enclosure: " << enclosure.numberOfAnimals << "\n";
    os << "The number of enclosures for this species that we currently have: " << enclosure.numberOfEnclosures << "\n";
    os << "The number of animals that are right now in the enclosure: " << enclosure.currentAnimalNumber << "\n\n";
    return os;
}

void Enclosure::addOneAnimal() {
    currentAnimalNumber++;
}
