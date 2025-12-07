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

void reptile::do_print_info() const {
    cout<<"Species: "<<species_name<<"\n";
    cout<<"The Health of the animals: "<<health<<"\n";
    cout<<"The number of animals: "<<number<<"\n";
    cout<<"The number of viewing platforms: "<<viewing_platform<<"\n";
    cout<<"The number of males: "<<male_number<<"\n";
    cout<<"The number of females: "<<female_number<<"\n";
    cout<<"The attractiveness (a number based on how rare this animal is): "<<attractiveness<<"\n";
    cout<<"The number of enclosures in which this creature lives: "<<enclosure_number<<"\n";
    cout<<"This reptile is "<<(cold_blooded?"":"not ")<<"cold blooded."<<"\n";
}


void reptile::print_details(ostream &os) const {
    animal::print_details(os);
    os<<"This reptile is "<<(cold_blooded?"":"not ")<<"cold blooded."<<"\n";
}


bool reptile:: is_cold_blooded()const{
    return cold_blooded;
}

