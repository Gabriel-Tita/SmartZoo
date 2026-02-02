#include "Zoo.hpp"
#include "Lion.hpp"
#include "Snake.hpp"
#include "Eagle.hpp"
#include "Zooexception.hpp"
#include "Treatment.hpp"

/**
 * @brief Adds a new animal family using polymorphic cloning.
 * @throws CloningFailureException if cloning fails.
 */
void Zoo::add(const Animal &a) {
    Animal *newAnimalPtr = a.clone();
    if (newAnimalPtr == nullptr) {
        throw CloningFailureException(a.getSpecies());
    }
    animals.push_back(unique_ptr<Animal>(newAnimalPtr));
    numberOfFamiliesOfAnimals++;
}

/**
 * @brief Stream insertion operator for a short zoo summary.
 */
ostream &operator<<(ostream &os, const Zoo &z) {
    os << "This is a list with all the creatures that we have!\n";
    for (int i = 0; i < z.numberOfFamiliesOfAnimals; i++) {
        os << "Creature number " << i + 1 << " : " << z.animals[i]->getSpecies() << "\n";
    }
    os << "\n";
    return os;
}

/**
 * @brief Prints detailed information about all stored animal families.
 */
void Zoo::printInfo() const {
    cout << "This is a list with all the creatures that we have and the information about them:\n";
    for (int i = 0; i < numberOfFamiliesOfAnimals; i++) {
        animals[i]->printInfo();
    }
}

/**
 * @brief Applies treatment to animals that implement the Treatment interface.
 */
void Zoo::veterinaryDay(std::ostream &os) {
    for (const auto &a: animals) {
        if (const auto *t = dynamic_cast<Treatment *>(a.get())) {
            t->applyTreatment(os);
        } else {
            os << "Skipping: animal not treatable.\n";
        }
    }
}

/**
 * @brief Adds one individual to a species and updates male/female counters.
 * @throws InvalidInputException If gender is not "Male" or "Female".
 * @throws AnimalNotFoundException If the species is not found in the zoo.
 */
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

/**
 * @brief Simulates a day by making animals produce sounds and running treatments.
 */
void Zoo::simulateDay(std::ostream &os) {
    os << "=== Daily routines ===\n";
    for (const auto &a: animals)
        a->makeSound();

    os << "\n=== Veterinary day ===\n";
    veterinaryDay(os);
}

/**
 * @brief Returns info (rating-like value) for a given species.
 */
int Zoo::getInfo(const string &name) const {
    for (int i = 0; i < numberOfFamiliesOfAnimals; i++) {
        if (name == animals[i]->getSpecies()) {
            return animals[i]->getMoreInfo();
        }
    }
    return 0;
}

/** @brief Initializes the static counter for animal families. */
int Zoo::numberOfFamiliesOfAnimals = 0;

/**
 * @brief Daily routine: prints info and checks sounds for all animals.
 */
void Zoo::dailyFeedAndSound() const {
    cout << "----Daily zoo event: feed and sound check----\n";
    for (const auto &a: animals) {
        a->printInfo();
        a->makeSound();
        std::cout << "-----------------------------\n";
    }
}

/** @brief Returns the number of animal families stored. */
int Zoo::getNumberOfFamilies() {
    return numberOfFamiliesOfAnimals;
}
