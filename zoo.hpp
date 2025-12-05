#pragma once
// #ifndef OOP_ZOO_HPP
// #define OOP_ZOO_HPP
#include <vector>
#include <iostream>
#include "animal.hpp"
using namespace std;

class zoo {
    //clasa care retine informatii generale despre fiecare specie din tarc(utila pentru ca putem cauta
    //mult mai usor informatii despre fiecare creatura utilizand NUMELE ei)
private:
    int number=-1;
    vector<animal> animals;
public:

    zoo()=default;

    explicit zoo(const int number);

    ~zoo()=default;

    friend ostream& operator<<(ostream& os, const zoo& zoo);

    void print_info();

    void add(const animal& animal);

    void add_individual(const string& name, const string& gender);

    int get_info(const string& name);

};
// #endif //OOP_ZOO_HPP