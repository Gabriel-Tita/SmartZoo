#include "mammal.hpp"
#include <algorithm>

mammal::mammal(const string &species_name, const string &health, const int number, const int viewing_platform,
               const int male_number, const int female_number, const int attractiveness, const int enclosure_number,
               const bool has_fur) : animal(species_name, health, number, viewing_platform, male_number, female_number,
                                            attractiveness, enclosure_number), has_fur(has_fur) {
}

mammal::mammal(const mammal &other) : animal(other), has_fur(other.has_fur) {
}

mammal &mammal::operator=(const mammal &other) {
    if (this != &other) {
        animal::operator=(other);
        has_fur = other.has_fur;
    }
    return *this;
}

void mammal::do_print_info() const {
    cout << "Species: " << species_name << "\n";
    cout << "The Health of the animals: " << health << "\n";
    cout << "The number of animals: " << number << "\n";
    cout << "The number of viewing platforms: " << viewing_platform << "\n";
    cout << "The number of males: " << male_number << "\n";
    cout << "The number of females: " << female_number << "\n";
    cout << "The attractiveness (a number based on how rare this animal is): " << attractiveness << "\n";
    cout << "The number of enclosures in which this creature lives: " << enclosure_number << "\n";
    cout << "This Mammal " << (has_fur ? "has fur." : "has no fur.") << "\n";
}

void mammal::print_details(ostream &os) const {
    animal::print_details(os);
    os << "This Mammal " << (has_fur ? "has fur." : "has no fur.") << "\n";
}

bool mammal::get_has_fur() const {
    return has_fur;
}

void mammal::swapp(mammal &other) {
    swap(has_fur, other.has_fur);
    swap(species_name, other.species_name);
    swap(health, other.health);
    swap(number, other.number);
    swap(viewing_platform, other.viewing_platform);
    swap(male_number, other.male_number);
    swap(female_number, other.female_number);
    swap(attractiveness, other.attractiveness);
    swap(enclosure_number, other.enclosure_number);
}
