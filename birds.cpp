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

void birds::do_print_info() const {
    cout<<"Species: "<<species_name<<"\n";
    cout<<"The Health of the animals: "<<health<<"\n";
    cout<<"The number of animals: "<<number<<"\n";
    cout<<"The number of viewing platforms: "<<viewing_platform<<"\n";
    cout<<"The number of males: "<<male_number<<"\n";
    cout<<"The number of females: "<<female_number<<"\n";
    cout<<"The attractiveness (a number based on how rare this animal is): "<<attractiveness<<"\n";
    cout<<"The number of enclosures in which this creature lives: "<<enclosure_number<<"\n";
    cout<<"This bird "<<(can_fly?"can ":"can't ")<<"fly."<<"\n";
}

bool birds::get_can_fly()const {
    return can_fly;
}
