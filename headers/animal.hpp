#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class animal {
    //clasa care retine informatii despre fiecare specie din parc
protected:
    string species_name = "Unknown", health = "Unknown";
    int number = -1, viewing_platform = -1, male_number = -1, female_number = -1, attractiveness = -1, enclosure_number
                    = -1;

    virtual void do_print_info() const =0;

public:
    animal() = default;

    animal(const string &species_name, const string &health, const int number, const int viewing_platform,
           const int male_number, const int female_number, const int attractiveness, const int enclosure_number);

    //contructor de copiere
    animal(const animal &animal);

    //operator egal (de atribuire)
    animal &operator=(const animal &animal);

    virtual ~animal() = default;

    // Prototype pattern: polymorphic copy (virtual constructor)
    virtual animal *clone() const =0;

    virtual void make_sound() const =0;

    virtual void print_details(ostream &os) const;

    friend ostream &operator<<(ostream &os, const animal &animal);

    virtual void print_info() const;

    const string &get_species() const;

    void update_gender_of_creatures(const string &gender);

    int get_more_info();
};
