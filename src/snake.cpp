#include "snake.hpp"

snake::snake(const string &species_name, const string &health, const int number, const int viewing_platform,
             const int male_number, const int female_number, const int attractiveness, const int enclosure_number,
             const bool cold_blooded, const bool is_poisonous)
    : reptile(species_name, health, number, viewing_platform, male_number, female_number, attractiveness,
              enclosure_number, cold_blooded), is_poisonous(is_poisonous) {
}

snake::snake(const snake &other) : reptile(other), is_poisonous(other.is_poisonous) {
}

snake &snake::operator=(const snake &other) {
    if (this != &other) {
        reptile::operator=(other);
        is_poisonous = other.is_poisonous;
    }
    return *this;
}

void snake::make_sound() const {
    cout << "HISSS" << "\n\n";
}

animal *snake::clone() const {
    return new snake(*this);
}

void snake::do_print_info() const {
    reptile::do_print_info();
    cout << "This snake " << (is_poisonous ? "is " : "isn't ") << "poisonous" << "\n";
}


void snake::print_details(ostream &os) const {
    reptile::print_details(os);
    os << "This snake " << (is_poisonous ? "is " : "isn't ") << "poisonous" << "\n\n";
}

bool snake::get_is_poisonous() const {
    return is_poisonous;
}

void snake::interesting_facts() const {
    if (this->is_cold_blooded() == 1 && this->get_is_poisonous() == 1) {
        cout << "This creature is cold blooded and poisonous!\n";
    }
}
