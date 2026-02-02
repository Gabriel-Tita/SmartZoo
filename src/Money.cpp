#include "Money.hpp"

/**
 * @brief Constructs a Money object with a given amount.
 */
Money::Money(int coins) {
    this->coins = coins;
}

/**
 * @brief Increases the wallet by a given amount.
 */
void Money::setWallet(int amountToBeAdded) {
    coins += amountToBeAdded;
}

/**
 * @brief Stream insertion operator for Money.
 */
std::ostream &operator<<(std::ostream &os, const Money &money) {
    os << "The budget of the zoo is " << money.coins << "!\n\n";
    return os;
}
