#include "Reptile.hpp"

reptile::reptile(const string& species_name, const string& health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, bool cold_blooded)
    : animal(species_name, health, number, viewing_platform, male_number, female_number, attractiveness, enclosure_number), cold_blooded(cold_blooded){}
reptile::reptile(const reptile &other): animal(other), cold_blooded(other.cold_blooded) {}
reptile& reptile::operator=(const reptile& other) {
    if (this!= &other) {
        animal::operator=(other);
        cold_blooded = other.cold_blooded;
    }
    return *this;
}

void reptile:: print_info() {
    animal::print_info();
    cout<<"This reptile is "<<(cold_blooded?"":"not ")<<"cold blooded."<<"\n";
}

void reptile::print_details(ostream &os) const {
    animal::print_details(os);
    os<<"This reptile is "<<(cold_blooded?"":"not ")<<"cold blooded."<<"\n";
}


bool reptile:: is_cold_blooded()const{
    return cold_blooded;
}

