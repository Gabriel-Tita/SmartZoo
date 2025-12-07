#include "lion.hpp"
#include <algorithm>

lion::lion(const string &species_name, const string &health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, const bool has_fur, const string &mane_colour)
    :mammal(species_name, health, number, viewing_platform, male_number, female_number, attractiveness, enclosure_number, has_fur), mane_colour(mane_colour){}
lion::lion(const lion &other): mammal(other), mane_colour(other.mane_colour) {}
lion& lion::operator=(lion other) {
    swapp(other);
    return *this;
}

void lion::make_sound()const{
    cout<<"ROAR"<<"\n\n";
}

animal* lion::clone()const {
    return new lion(*this);
}

void lion::print_details(ostream& os)const {
    mammal::print_details(os);
    os<<"Mane colour: "<<mane_colour<<"\n\n";
}

void lion::do_print_info() const {
    mammal::do_print_info();
    cout<<"Mane colour: "<<mane_colour<<"\n";
}


const string& lion::get_mane_colour() const {
    return mane_colour;
}

void lion::interesting_facts() const{
    if (this->get_has_fur()==1) {
        cout<<"This creature has fur and a mane of colour "<<this->get_mane_colour()<<"!\n";
    }
}

void lion::swapp(lion& other) {
    swap(mane_colour, other.mane_colour);
    mammal::swapp(other);
}
