#include "Zoo.hpp"
#include "Lion.hpp"
#include "Snake.hpp"
#include "Eagle.hpp"
#include "Zooexception.hpp"
#include "Treatment.hpp"

void Zoo::add(const Animal &a) {
    Animal *newAnimalPtr = a.clone();
    if (newAnimalPtr == nullptr) {
        throw CloningFailureException(a.getSpecies());
    }
    animals.push_back(unique_ptr<Animal>(newAnimalPtr));
    numberOfFamiliesOfAnimals++;
}

ostream &operator<<(ostream &os, const Zoo &z) {
    os << "This is a list with all the creatures that we have!\n";
    for (int i = 0; i < z.numberOfFamiliesOfAnimals; i++) {
        os << "Creature number " << i + 1 << " : " << z.animals[i]->getSpecies() << "\n";
    }
    os << "\n";
    return os;
}

void Zoo::printInfo() const {
    cout << "This is a list with all the creatures that we have and the information about them:\n";
    for (int i = 0; i < numberOfFamiliesOfAnimals; i++) {
        animals[i]->printInfo();
    }
}

void Zoo::veterinaryDay(std::ostream& os) {
    for (const auto& a : animals) {
        if (auto* t = dynamic_cast<Treatment*>(a.get())) {
            t->applyTreatment(os);
        } else {
            os << "Skipping: animal not treatable.\n";
        }
    }
}

void Zoo::addIndividual(const string &name, const string &gender) {
    if (gender != "Male" && gender != "Female") {
        throw InvalidInputException(gender);
    }
    for (int i = 0; i < numberOfFamiliesOfAnimals; i++) {
        if (name == animals[i]->getSpecies()) {
            animals[i]->updateGenderOfCreatures(gender);
            return;
        }
    }
    throw AnimalNotFoundException(name);
}

void Zoo::simulateDay(std::ostream& os) {
    os << "=== Daily routines ===\n";
    for (const auto& a : animals)
        a->makeSound();

    os << "\n=== Veterinary day ===\n";
    veterinaryDay(os);
}

int Zoo::getInfo(const string &name) const {
    for (int i = 0; i < numberOfFamiliesOfAnimals; i++) {
        if (name == animals[i]->getSpecies()) {
            return animals[i]->getMoreInfo();
        }
    }
    return 0;
}

int Zoo::numberOfFamiliesOfAnimals = 0;

void Zoo::dailyFeedAndSound() const {
    cout << "----Daily zoo event: feed and sound check----\n";
    for (const auto &a: animals) {
        a->printInfo();
        a->makeSound();
        std::cout << "-----------------------------\n";
    }
}

int Zoo::getNumberOfFamilies() {
    return numberOfFamiliesOfAnimals;
}
