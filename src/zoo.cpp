#include "zoo.hpp"
#include "lion.hpp"
#include "snake.hpp"
#include "eagle.hpp"
#include "zooexception.hpp"
#include "Tratament.hpp"

void zoo::add(const animal &a) {
    animal *new_animal_ptr = a.clone();
    if (new_animal_ptr == nullptr) {
        throw cloning_failure_exception(a.get_species());
    }
    animals.push_back(unique_ptr<animal>(new_animal_ptr));
    number_of_families_of_animals++;
}

ostream &operator<<(ostream &os, const zoo &z) {
    os << "This is a list with all the creatures that we have!\n";
    for (int i = 0; i < z.number_of_families_of_animals; i++) {
        os << "Creature number " << i + 1 << " : " << z.animals[i]->get_species() << "\n";
    }
    os << "\n";
    return os;
}

void zoo::print_info() {
    cout << "This is a list with all the creatures that we have and the information about them:\n";
    for (int i = 0; i < number_of_families_of_animals; i++) {
        animals[i]->print_info();
    }
}

void zoo::veterinary_day(std::ostream& os) {
    for (const auto& a : animals) {  // animals = vector<shared_ptr<animal>> (probabil)
        if (auto* t = dynamic_cast<Tratament*>(a.get())) {
            t->applyTreatment(os);
        } else {
            os << "Skipping: animal not treatable.\n";
        }
    }
}

void zoo::add_individual(const string &name, const string &gender) {
    if (gender != "Male" && gender != "Female") {
        throw invalid_input_exception(gender);
    }
    for (int i = 0; i < number_of_families_of_animals; i++) {
        if (name == animals[i]->get_species()) {
            animals[i]->update_gender_of_creatures(gender);
            return;
        }
    }
    throw animal_not_found_exception(name);
}

int zoo::get_info(const string &name) {
    for (int i = 0; i < number_of_families_of_animals; i++) {
        if (name == animals[i]->get_species()) {
            return animals[i]->get_more_info();
        }
    }
    return 0;
}

// int zoo::get_curent_number() const{
//     return number;
// }

int zoo::number_of_families_of_animals = 0;

void zoo::daily_feed_and_sound() const {
    cout << "----Daily zoo event: feed and sound check----\n";
    for (const auto &a: animals) {
        a->print_info();
        a->make_sound();
        std::cout << "-----------------------------\n";
    }
}

int zoo::get_number_of_families() {
    return number_of_families_of_animals;
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
