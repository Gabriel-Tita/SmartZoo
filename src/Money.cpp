#include "Money.hpp"

Money::Money(int coins) {
    this->coins = coins;
}

void Money::setWallet(int amountToBeAdded) {
    coins += amountToBeAdded;
}

std::ostream &operator<<(std::ostream &os, const Money &money) {
    os << "The budget of the zoo is " << money.coins << "!\n\n";
    return os;
}
