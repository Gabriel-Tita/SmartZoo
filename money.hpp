#ifndef OOP_MONEY_HPP
#define OOP_MONEY_HPP
#include <iostream>
using namespace std;

class money {
private:
    int coins=-1;
public:
    money()=default;

    explicit money(const int coins);

    void set_wallet(const int amount_to_be_added);

    ~money()=default;

    friend ostream& operator<<(ostream& os, const money money);
};
#endif //OOP_MONEY_HPP