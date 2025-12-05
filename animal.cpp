// #pragma once
#include "animal.hpp"

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

animal::~animal() {
    cout<<"\n";
}

ostream& operator<<(ostream& os, const animal& animal) {
    os<<"This is what we know about the next animal!"<<"\n";
    os<<"Species: "<<animal.species_name<<"\n";
    os<<"The Health of the animals: "<<animal.health<<"\n";
    os<<"The number of animals: "<<animal.number<<"\n";
    os<<"The number of viewing platforms: "<<animal.viewing_platform<<"\n";
    os<<"The number of males: "<<animal.male_number<<"\n";
    os<<"The number of females: "<<animal.female_number<<"\n";
    os<<"The attractiveness (a number based on how rare this animal is): "<<animal.attractiveness<<"\n";
    os<<"The number of enclosures in which this creature lives: "<<animal.enclosure_number<<"\n\n";
    return os;
}

void animal::print_info()
{
    cout<<"This is what we know about the next animal!"<<"\n";
    cout<<"Species: "<<species_name<<"\n";
    cout<<"The Health of the animals: "<<health<<"\n";
    cout<<"The number of animals: "<<number<<"\n";
    cout<<"The number of viewing platforms: "<<viewing_platform<<"\n";
    cout<<"The number of males: "<<male_number<<"\n";
    cout<<"The number of females: "<<female_number<<"\n";
    cout<<"The attractiveness (a number based on how rare this animal is): "<<attractiveness<<"\n";
    cout<<"The number of enclosures in which this creature lives: "<<enclosure_number<<"\n\n";
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
