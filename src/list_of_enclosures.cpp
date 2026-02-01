#include "list_of_enclosures.hpp"

int list_of_enclosures::number = 0;

int list_of_enclosures::get_number_of_enclosures() {
    return number;
}

const string &list_of_enclosures::get_enclosure_species(const int num) const {
    return enc[num].get_species();
}

void list_of_enclosures::add(const enclosure &Enclosure) {
    enc.push_back(Enclosure);
    number++;
}

void list_of_enclosures::query_add_animal(zoo &species, const string &name, const string &gender) {
    for (int i = 0; i < number; i++) {
        if (name == enc[i].get_species()) {
            if (enc[i].get_current_animals_number() < enc[i].get_number_of_animals()) {
                enc[i].add_one_animal();
                cout << "We added the creature in the enclosure number " << i + 1 << ".\n\n";
                species.add_individual(name, gender);
                return;
            }
        }
    }
    cout << "We couldn't add the creature in any enclosure.\n";
}

void list_of_enclosures::print_info() {
    cout << "This is a list of all the enclosures that we currently have: " << "\n";
    for (int i = 0; i < number; i++) {
        cout << "Number " << i + 1 << ": " << "\n" << enc[i];
    }
}

ostream &operator<<(ostream &os, const list_of_enclosures &list_of_enclosures) {
    os << "This is a list of all the enclosures that we currently have: " << "\n";
    for (int i = 0; i < list_of_enclosures.number; i++) {
        os << "Number " << i + 1 << ": " << "\n" << list_of_enclosures.enc[i];
    }
    return os;
}
