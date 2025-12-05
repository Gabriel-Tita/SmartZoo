// #pragma once
#include "enclosure.hpp"
// clasa care retine informatii despre tarcurile fiecarei specii

enclosure::enclosure(const string& species, const int number_of_animals, const int number_of_enclosures, const int current_animal_number) {
    this->species=species;
    this->number_of_animals=number_of_animals;
    this->number_of_enclosures=number_of_enclosures;
    this->current_animal_number=current_animal_number;
}

const string& enclosure::get_species() const{
    return species;
}

int enclosure::get_number_of_animals() {
    return number_of_animals;
}

int enclosure::get_current_animals_number() const {
    return current_animal_number;
}

void enclosure::print_info() {
    cout<<"This is everything about the enclosures of the ";
    cout<<species<<"!\n";
    cout<<"The number of animals that can coexist in one single enclosure: "<<number_of_animals<<"\n";
    cout<<"The number of enclosures for this species that we currently have: "<<number_of_enclosures<<"\n";
    cout<<"The number of animals that are right now in the enclosure: "<<current_animal_number<<"\n\n";
}

ostream& operator<<(ostream& os, const enclosure& enclosure) {
    os<<"This is everything about the enclosures of the ";
    os<<enclosure.species<<"!\n";
    os<<"The number of animals that can coexist in one single enclosure: "<<enclosure.number_of_animals<<"\n";
    os<<"The number of enclosures for this species that we currently have: "<<enclosure.number_of_enclosures<<"\n";
    os<<"The number of animals that are right now in the enclosure: "<<enclosure.current_animal_number<<"\n\n";
    return os;
}

void enclosure::add_one_animal() {
    current_animal_number++;
}