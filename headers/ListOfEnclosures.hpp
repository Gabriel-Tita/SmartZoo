#pragma once
#include <iostream>
#include "Enclosure.hpp"
#include "Zoo.hpp"
using namespace std;

class ListOfEnclosures {
private:
    // clasa care retine cate tarcuri avem pentru fiecare specie
    static int number;
    vector<Enclosure> enc;

public:
    ListOfEnclosures() = default;

    ~ListOfEnclosures() = default;

    static int getNumberOfEnclosures();

    const string &getEnclosureSpecies(int num) const;

    void add(const Enclosure &Enclosure);

    void queryAddAnimal(Zoo &species, const string &name, const string &gender);

    void printInfo() const;

    friend ostream &operator<<(ostream &os, const ListOfEnclosures &listOfEnclosures);
};
