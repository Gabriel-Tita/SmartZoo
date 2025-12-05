#ifndef OOP_ANIMAL_HPP
#define OOP_ANIMAL_HPP
#include <string>
#include <iostream>
using namespace std;

class animal {
    //clasa care retine informatii despre fiecare specie din parc
private:
    string species_name="Unknown", health="Unknown";
    int number=-1, viewing_platform=-1, male_number=-1, female_number=-1, attractiveness=-1, enclosure_number=-1;
public:
    animal()=default;

    animal(const string& species_name, const string& health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number);

    //contructor de copiere
    animal(const animal& animal);

    //operator egal (de atribuire)
    animal& operator=(const animal& animal);

    ~animal();

    friend ostream& operator<<(ostream& os, const animal& animal);

    void print_info();

    const string& get_species () const;

    void update_gender_of_creatures(const string& gender);

    int get_more_info();
};
#endif //OOP_ANIMAL_HPP