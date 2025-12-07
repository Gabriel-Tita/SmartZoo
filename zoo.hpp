#pragma once
#include <vector>
#include <iostream>
#include "animal.hpp"
using namespace std;

class zoo {
    //clasa care retine informatii generale despre fiecare specie din tarc(utila pentru ca putem cauta
    //mult mai usor informatii despre fiecare creatura utilizand NUMELE ei)
private:
    int number=0;
    vector<animal*> animals;
public:

    zoo()=default;

    explicit zoo(const int number);

    ~zoo();

    friend ostream& operator<<(ostream& os, const zoo& zoo);

    void print_info();

    void add(const animal& animal);

    void add_individual(const string& name, const string& gender);

    int get_info(const string& name);

    // int get_curent_number() const;

    void daily_feed_and_sound () const;

};