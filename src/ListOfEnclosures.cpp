#include "ListOfEnclosures.hpp"

int ListOfEnclosures::number = 0;

int ListOfEnclosures::getNumberOfEnclosures() {
    return number;
}

const string &ListOfEnclosures::getEnclosureSpecies(int num) const {
    return enc[num].getSpecies();
}

void ListOfEnclosures::add(const Enclosure &Enclosure) {
    enc.push_back(Enclosure);
    number++;
}

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

void ListOfEnclosures::printInfo() const {
    cout << "This is a list of all the enclosures that we currently have: " << "\n";
    for (int i = 0; i < number; i++) {
        cout << "Number " << i + 1 << ": " << "\n" << enc[i];
    }
}

ostream &operator<<(ostream &os, const ListOfEnclosures &listOfEnclosures) {
    os << "This is a list of all the enclosures that we currently have: " << "\n";
    for (int i = 0; i < listOfEnclosures.number; i++) {
        os << "Number " << i + 1 << ": " << "\n" << listOfEnclosures.enc[i];
    }
    return os;
}
