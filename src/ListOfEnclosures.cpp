#include "ListOfEnclosures.hpp"

/** @brief Initializes the static enclosure counter. */
int ListOfEnclosures::number = 0;

/** @brief Returns the total number of enclosures. */
int ListOfEnclosures::getNumberOfEnclosures() {
    return number;
}

/**
 * @brief Returns the species name of the enclosure at a given index.
 */
const string &ListOfEnclosures::getEnclosureSpecies(int num) const {
    return enc[num].getSpecies();
}

/**
 * @brief Adds a new enclosure and increases the counter.
 */
void ListOfEnclosures::add(const Enclosure &Enclosure) {
    enc.push_back(Enclosure);
    number++;
}

/**
 * @brief Adds an animal to the first available enclosure of the given species.
 */
void ListOfEnclosures::queryAddAnimal(Zoo &species, const string &name, const string &gender) {
    for (int i = 0; i < number; i++) {
        if (name == enc[i].getSpecies()) {
            if (enc[i].getCurrentAnimalsNumber() < enc[i].getNumberOfAnimals()) {
                enc[i].addOneAnimal();
                cout << "We added the creature in the enclosure number " << i + 1 << ".\n\n";
                species.addIndividual(name, gender);
                return;
            }
        }
    }
    cout << "We couldn't add the creature in any enclosure.\n";
}

/**
 * @brief Prints information about all enclosures.
 */
void ListOfEnclosures::printInfo() const {
    cout << "This is a list of all the enclosures that we currently have: " << "\n";
    for (int i = 0; i < number; i++) {
        cout << "Number " << i + 1 << ": " << "\n" << enc[i];
    }
}

/**
 * @brief Stream insertion operator for ListOfEnclosures.
 */
ostream &operator<<(ostream &os, const ListOfEnclosures &listOfEnclosures) {
    os << "This is a list of all the enclosures that we currently have: " << "\n";
    for (int i = 0; i < listOfEnclosures.number; i++) {
        os << "Number " << i + 1 << ": " << "\n" << listOfEnclosures.enc[i];
    }
    return os;
}
