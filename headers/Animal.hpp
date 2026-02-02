#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Animal {
    //clasa care retine informatii despre fiecare specie din parc
protected:
    string speciesName = "Unknown", health = "Unknown";
    int number = -1, viewingPlatform = -1, maleNumber = -1, femaleNumber = -1, attractiveness = -1, enclosureNumber
                    = -1;

    virtual void doPrintInfo() const = 0;

public:
    Animal() = default;

    Animal(const string &speciesName, const string &health, int number, int viewingPlatform,
           int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber);

    //contructor de copiere
    Animal(const Animal &animal);

    //operator egal (de atribuire)
    Animal &operator=(const Animal &animal);

    virtual ~Animal() = default;

    // Prototype pattern: polymorphic copy (virtual constructor)
    virtual Animal *clone() const = 0;

    virtual void makeSound() const = 0;

    virtual void printDetails(ostream &os) const;

    friend ostream &operator<<(ostream &os, const Animal &animal);

    virtual void printInfo() const;

    const string &getSpecies() const;

    void updateGenderOfCreatures(const string &gender);

    int getMoreInfo() const;
};
