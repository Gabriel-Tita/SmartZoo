#include "eagle.hpp"

eagle::eagle(const string& species_name, const string& health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, bool can_fly, const double wingspan)
    :birds(species_name, health, number, viewing_platform, male_number, female_number, attractiveness, enclosure_number, can_fly), wingspan(wingspan){}
eagle::eagle(const eagle &other): birds(other), wingspan(other.wingspan){}
eagle& eagle::operator=(const eagle &other) {
    if (this !=&other) {
        birds::operator=(other);
        wingspan = other.wingspan;
    }
    return *this;
}

void eagle::make_sound() const {
    cout<<"SCREECH"<<"\n\n";
}

animal* eagle::clone() const {
    return new eagle(*this);
}

void eagle::print_details(ostream& os) const {
    birds::print_details(os);
    os<<"This eagle has a wingspan of "<<wingspan<<" meters!"<<"\n\n";
}

void eagle::print_info(){
    birds::print_info();
    cout<<"This eagle has a wingspan of "<<wingspan<<" meters!"<<"\n";
}
double eagle::get_wingspan() const {
    return wingspan;
}

void eagle::interesting_facts() const {
    if (this->get_can_fly()==1) {
        cout<<"This eagle can fly and has a wingspan of "<<this->get_wingspan()<<"!\n";
    }
}


