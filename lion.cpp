#include "lion.hpp"

lion::lion(const string &species_name, const string &health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, const bool has_fur, const string &mane_colour)
    :mammal(species_name, health, number, viewing_platform, male_number, female_number, attractiveness, enclosure_number, has_fur), mane_colour(mane_colour){}
lion::lion(const lion &other): mammal(other), mane_colour(other.mane_colour) {}
lion& lion::operator=(const lion &other) {
    if (this !=&other) {
        mammal::operator=(other);
        mane_colour = other.mane_colour;
    }
    return *this;
}

void lion::make_sound()const{
    cout<<"ROAR"<<"\n\n";
}

animal* lion::clone()const {
    return new lion(*this);
}

void lion::print_details(ostream& os)const {
    animal::print_details(os);
    os<<"Mane colour: "<<mane_colour<<"\n\n";
}

void lion::print_info(){
    mammal::print_info();
    cout<<"Mane colour: "<<mane_colour<<"\n";
}

const string& lion::get_mane_colour() const {
    return mane_colour;
}
