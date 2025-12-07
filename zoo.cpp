#include "zoo.hpp"
#include "lion.hpp"
#include "snake.hpp"
#include "eagle.hpp"
zoo::zoo(const int number) {
    this->number=number;
    this->number=0;
}

void zoo::add(const animal& a) {
    animals.push_back(unique_ptr<animal>(a.clone()));
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
    for (const auto& a:animals) {
        a->print_info();
        a->make_sound();
        std::cout<<"-----------------------------\n";
    }
}

void zoo::apply_special_treatment() {
    cout<<"----Applying special treatment----\n";
    for (const auto& animal_ptr:animals) {
        const lion* lion_ptr=dynamic_cast<lion*>(animal_ptr.get());
        if (lion_ptr) {
            cout<<"Lion: Apply speical treatment for the mane colour: "<<lion_ptr->get_mane_colour()<<"\n";
        }
        const eagle* eagle_ptr=dynamic_cast<eagle*>(animal_ptr.get());
        if (eagle_ptr) {
            cout<<"Eagle: Apply special treatment for its feathers\n";
        }
        const snake* snake_ptr=dynamic_cast<snake*>(animal_ptr.get());
        if (snake_ptr) {
            cout<<"Snake: Apply special treatment for its fangs\n";
        }
    }
    cout<<"\n";
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