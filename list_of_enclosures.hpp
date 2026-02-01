#pragma once
#include <iostream>
#include "enclosure.hpp"
#include "zoo.hpp"
using namespace std;

class list_of_enclosures {
private:
    // clasa care retine cate tarcuri avem pentru fiecare specie
    static int number;
    vector<enclosure> enc;

public:
    list_of_enclosures() = default;

    ~list_of_enclosures() = default;

    static int get_number_of_enclosures();

    const string &get_enclosure_species(const int num) const;

    void add(const enclosure &Enclosure);

    void query_add_animal(zoo &species, const string &name, const string &gender);

    void print_info();

    friend ostream &operator<<(ostream &os, const list_of_enclosures &list_of_enclosures);
};
