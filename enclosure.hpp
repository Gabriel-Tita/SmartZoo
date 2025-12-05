#pragma once
// #ifndef OOP_ENCLOSURE_HPP
// #define OOP_ENCLOSURE_HPP
#include <string>
#include <iostream>
using namespace std;

class enclosure {
    // clasa care retine informatii despre tarcurile fiecarei specii
private:
    string species="Unknown";
    int number_of_animals=-1, number_of_enclosures=-1, current_animal_number=-1;
public:
    enclosure()=default;

    enclosure(const string& species, const int number_of_animals, const int number_of_enclosures, const int current_animal_number);

    ~enclosure()=default;

    const string& get_species()const;

    int get_number_of_animals();

    int get_current_animals_number()const ;

    void print_info();

    friend ostream& operator<<(ostream& os, const enclosure& enclosure);

    void add_one_animal();
};
//#endif //OOP_ENCLOSURE_HPP