#pragma once
#include <iostream>
using namespace std;

class Money {
private:
    int coins = -1;

public:
    Money() = default;

    explicit Money(int coins);

    void setWallet(int amountToBeAdded);

    ~Money() = default;

    friend ostream &operator<<(ostream &os, const Money &money);
};
