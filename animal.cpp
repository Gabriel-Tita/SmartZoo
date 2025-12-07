#include "animal.hpp"
#include <algorithm>


animal::animal(const string& species_name, const string& health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number)
{
    this->species_name=species_name;
    this->health=health;
    this->number=number;
    this->viewing_platform=viewing_platform;
    this->male_number=male_number;
    this->female_number=female_number;
    this->attractiveness=attractiveness;
    this->enclosure_number=enclosure_number;
}

//contructor de copiere
animal::animal(const animal& animal) {
    this->species_name=animal.species_name;
    this->health=animal.health;
    this->number=animal.number;
    this->viewing_platform=animal.viewing_platform;
    this->male_number=animal.male_number;
    this->female_number=animal.female_number;
    this->attractiveness=animal.attractiveness;
    this->enclosure_number=animal.enclosure_number;
}

//operator egal (de atribuire)
animal& animal::operator=(const animal& animal) {
    this->species_name=animal.species_name;
    this->health=animal.health;
    this->number=animal.number;
    this->viewing_platform=animal.viewing_platform;
    this->male_number=animal.male_number;
    this->female_number=animal.female_number;
    this->attractiveness=animal.attractiveness;
    this->enclosure_number=animal.enclosure_number;
    return *this;
}


void animal::print_details(ostream& os) const {
    os<<"Species: "<<species_name<<"\n";
    os<<"The Health of the animals: "<<health<<"\n";
    os<<"The number of animals: "<<number<<"\n";
    os<<"The number of viewing platforms: "<<viewing_platform<<"\n";
    os<<"The number of males: "<<male_number<<"\n";
    os<<"The number of females: "<<female_number<<"\n";
    os<<"The attractiveness (a number based on how rare this animal is): "<<attractiveness<<"\n";
    os<<"The number of enclosures in which this creature lives: "<<enclosure_number<<"\n";
}

ostream& operator<<(ostream& os, const animal& animal) {
    os<<"This is what we know about the next animal!"<<"\n";
    animal.print_details(os);
    return os;
}

void animal::print_info() const{
    this->do_print_info();
}

const string& animal::get_species () const {
    return species_name;
}

void animal::update_gender_of_creatures(const string& gender){
    // enum
    number++;
    if (gender=="Male") {
        male_number++;
    }
    else {
        female_number++;
    }
}

int animal::get_more_info() {
    return number*attractiveness;
}
