#pragma once
#include <string>
#include <iostream>
using namespace std;

class Enclosure {
private:
    string species = "Unknown";
    int numberOfAnimals = -1, numberOfEnclosures = -1, currentAnimalNumber = -1;

public:
    Enclosure() = default;

    Enclosure(const string &species, int numberOfAnimals, int numberOfEnclosures,
              int currentAnimalNumber);

    ~Enclosure() = default;

    const string &getSpecies() const;

    int getNumberOfAnimals() const;

    int getCurrentAnimalsNumber() const;

    void printInfo() const;

    friend ostream &operator<<(ostream &os, const Enclosure &enclosure);

    void addOneAnimal();
};
