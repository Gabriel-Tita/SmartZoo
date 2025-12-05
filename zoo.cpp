#include "zoo.hpp"
//clasa care retine informatii generale despre fiecare specie din tarc(utila pentru ca putem cauta
    //mult mai usor informatii despre fiecare creatura utilizand NUMELE ei)
zoo::zoo(const int number) {
    this->number=number;
}

ostream& operator<<(ostream& os, const zoo& zoo) {
    os<<"This is a list with all the creatures that we have!\n";
    for(int i=0;i<zoo.number;i++) {
        os<<"Creature number "<<i+1<<" : "<<zoo.animals[i].get_species()<<"\n";
    }
    os<<"\n";
    return os;
}

void zoo::print_info() {
    cout<<"This is a list with all the creatures that we have and the information about them:\n";
    for (int i=0;i<number;i++) {
        cout<<animals[i];
    }
}

void zoo::add(const animal& animal) {
    animals.push_back(animal);
    number++;
}

void zoo::add_individual(const string& name, const string& gender) {
    for (int i=0;i<number;i++) {
        if (name==animals[i].get_species()) {
            animals[i].update_gender_of_creatures(gender);
            return;
        }
    }
}

int zoo::get_info(const string& name) {
    for (int i=0;i<number;i++) {
        if (name==animals[i].get_species()) {
            return animals[i].get_more_info();
        }
    }
    return 0;
}
