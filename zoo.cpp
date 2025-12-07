#include "zoo.hpp"
zoo::zoo(const int number) {
    this->number=number;
    this->number=0;
}

zoo::~zoo() {
    for (animal* a:animals) {
        delete a;
    }
    animals.clear();
    number=0;
}

void zoo::add(const animal& a) {
    animals.push_back(a.clone());
    number++;
}

ostream& operator<<(ostream& os, const zoo& z) {
    os<<"This is a list with all the creatures that we have!\n";
    for (int i=0;i<z.number;i++) {
        os<<"Creature number "<<i+1<<" : "<<z.animals[i]->get_species()<<"\n";
    }
    os<<"\n";
    return os;
}

void zoo::print_info() {
    cout<<"This is a list with all the creatures that we have and the information about them:\n";
    for (int i=0;i<number;i++) {
        animals[i]->print_info();
    }
}

void zoo::add_individual(const string &name, const string &gender) {
    for (int i=0;i<number;i++) {
        if (name==animals[i]->get_species()) {
            animals[i]->update_gender_of_creatures(gender);
            return;
        }
    }
}

int zoo::get_info(const string &name) {
    for (int i=0;i<number;i++) {
        if (name==animals[i]->get_species()) {
            return animals[i]->get_more_info();
        }
    }
    return 0;
}

// int zoo::get_curent_number() const{
//     return number;
// }

void zoo::daily_feed_and_sound() const {
    cout<<"----Daily zoo event: feed and sound check----\n";
    for (const animal* a:animals) {
        a->print_info();
        a->make_sound();
        std::cout<<"-----------------------------\n";
    }
}



// ostream& operator<<(ostream& os, const zoo& zoo) {
//     os<<"This is a list with all the creatures that we have!\n";
//     for(int i=0;i<zoo.number;i++) {
//         os<<"Creature number "<<i+1<<" : "<<zoo.animals[i].get_species()<<"\n";
//     }
//     os<<"\n";
//     return os;
// }
//
// void zoo::print_info() {
//     cout<<"This is a list with all the creatures that we have and the information about them:\n";
//     for (int i=0;i<number;i++) {
//         cout<<animals[i];
//     }
// }
//
// void zoo::add(const animal& animal) {
//     animals.push_back(animal);
//     number++;
// }
//
// void zoo::add_individual(const string& name, const string& gender) {
//     for (int i=0;i<number;i++) {
//         if (name==animals[i].get_species()) {
//             animals[i].update_gender_of_creatures(gender);
//             return;
//         }
//     }
// }
//
// int zoo::get_info(const string& name) {
//     for (int i=0;i<number;i++) {
//         if (name==animals[i].get_species()) {
//             return animals[i].get_more_info();
//         }
//     }
//     return 0;
// }
