#include "crocodile.hpp"
crocodile::crocodile(const string &species_name, const string &health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, const bool cold_blooded, const bool lives_in_salty_waters)
    :reptile(species_name, health, number, viewing_platform, male_number, female_number, attractiveness, enclosure_number, cold_blooded), lives_in_salty_waters(lives_in_salty_waters){}
crocodile::crocodile(const crocodile &other):reptile(other), lives_in_salty_waters(other.lives_in_salty_waters){}
crocodile& crocodile::operator=(const crocodile& other) {
    if (this !=&other) {
        reptile::operator=(other);
        lives_in_salty_waters=other.lives_in_salty_waters;
    }
    return *this;
}

void crocodile::make_sound() const {
    cout<<"GGRRR-AOH"<<"\n\n";
}

animal *crocodile::clone() const {
    return new crocodile(*this);
}

void crocodile::do_print_info() const {
    reptile::do_print_info();
    cout<<"This crocodile lives in "<<(lives_in_salty_waters?"salty ":"sweet ")<<"waters"<<"\n";
}


void crocodile::print_details(ostream& os) const {
    reptile::print_details(os);
    os<<"This crocodile lives in "<<(lives_in_salty_waters?"salty ":"sweet ")<<"waters"<<"\n\n";
}

bool crocodile::get_lives_in_salty_waters() const{
    return lives_in_salty_waters;
}

void crocodile::interesting_facts() const{
    if (this->is_cold_blooded()==1&&this->get_lives_in_salty_waters()==1) {
        cout<<"This creature is cold blooded and lives in salty waters!\n";
    }
}