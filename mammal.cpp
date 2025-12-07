#include "mammal.hpp"

mammal::mammal(const string &species_name, const string &health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, const bool has_fur):
    animal(species_name, health, number, viewing_platform, male_number, female_number, attractiveness, enclosure_number), has_fur(has_fur){}
mammal::mammal(const mammal &other): animal(other), has_fur(other.has_fur) {}
mammal& mammal::operator=(const mammal &other) {
    if (this != &other) {
        animal::operator=(other);
        has_fur = other.has_fur;
    }
    return *this;
}

void mammal::print_info() {
    animal::print_info();
    cout<<"This Mammal "<<(has_fur?"has fur.": "has no fur.")<<"\n";
}

void mammal::print_details(ostream& os) const{
    animal::print_details(os);
    os<<"This Mammal "<<(has_fur?"has fur.": "has no fur.")<<"\n";
}

bool mammal::get_has_fur()const {
    return has_fur;
}