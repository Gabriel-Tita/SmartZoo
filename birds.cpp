#include "birds.hpp"

birds::birds(const string& species_name, const string& health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, bool can_fly)
    :animal(species_name, health, number, viewing_platform, male_number, female_number, attractiveness, enclosure_number), can_fly(can_fly){}
birds::birds(const birds &other) :
    animal(other), can_fly(other.can_fly){};
birds & birds::operator=(const birds& other) {
    if (this!= &other){
        animal::operator=(other);
        can_fly = other.can_fly;
    }
    return *this;
}

void birds::print_details(ostream& os)const {
    animal::print_details(os);
    os<<"This bird "<<(can_fly?"can ":"can't ")<<"fly."<<"\n";
}

void birds::print_info() {
    animal::print_info();
    cout<<"This bird "<<(can_fly?"can ":"can't ")<<"fly."<<"\n";
}

bool birds::get_can_fly()const {
    return can_fly;
}
