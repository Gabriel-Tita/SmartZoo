#include "money.hpp"

money::money(const int coins) {
    this->coins = coins;
}

void money::set_wallet(const int amount_to_be_added) {
    coins += amount_to_be_added;
}

std::ostream &operator<<(std::ostream &os, const money &money) {
    os << "The budget of the zoo is " << money.coins << "!\n\n";
    return os;
}
