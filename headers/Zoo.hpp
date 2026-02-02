#pragma once
#include <vector>
#include <iostream>
#include "Animal.hpp"
#include <memory>
using namespace std;

class Zoo {
private:
    vector<unique_ptr<Animal> > animals;
    static int numberOfFamiliesOfAnimals;

public:
    static int getNumberOfFamilies();

    Zoo() = default;

    ~Zoo() = default;

    friend ostream &operator<<(ostream &os, const Zoo &zoo);

    void printInfo() const;

    void veterinaryDay(std::ostream& os);

    void add(const Animal &animal);

    void addIndividual(const string &name, const string &gender);

    int getInfo(const string &name) const;

    void simulateDay(std::ostream& os);

    void dailyFeedAndSound() const;
};
