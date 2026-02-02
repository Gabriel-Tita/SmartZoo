#pragma once
#include <iostream>
using namespace std;

/**
 * @class Money
 * @brief Represents the zoo's budget.
 *
 * Stores and updates the amount of coins available.
 */
class Money {
private:
    /** @brief Current amount of coins. */
    int coins = -1;

public:
    /** @brief Default constructor. */
    Money() = default;

    /**
     * @brief Constructs a Money object with an initial amount.
     * @param coins Initial number of coins.
     */
    explicit Money(int coins);

    /**
     * @brief Adds coins to the wallet.
     * @param amountToBeAdded Amount to add.
     */
    void setWallet(int amountToBeAdded);

    /** @brief Destructor. */
    ~Money() = default;

    /** @brief Output operator for printing the budget. */
    friend ostream &operator<<(ostream &os, const Money &money);
};
