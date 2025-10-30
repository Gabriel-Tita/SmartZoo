#include <iostream>
#include <string>
using namespace std;

class enclosure
{
private:
    string species;
    int number_of_animals, number_of_enclosures;
public:
    enclosure()=default;

    enclosure(const string& species, const int number_of_animals, const int number_of_enclosures) {
        this->species=species;
        this->number_of_animals=number_of_animals;
        this->number_of_enclosures=number_of_enclosures;
    }
};

class animal
{
private:
    string species_name, health;
    int number, viewing_platform, male_number, female_number, attractiveness, enclosure_number;
public:
    animal()=default;

    animal(const string& species_name, const string& health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number)
    {
        this->species_name=species_name;
        this->health=health;
        this->number=number;
        this->viewing_platform=viewing_platform;
        this->male_number=male_number;
        this->female_number=female_number;
        this->attractiveness=attractiveness;
        this->enclosure_number=enclosure_number;
    }

    void afisare_informatii()
    {
        cout<<species_name<<", ";
        cout<<health<<", ";
        cout<<number<<", ";
        cout<<viewing_platform<<", ";
        cout<<male_number<<", ";
        cout<<female_number<<", ";
        cout<<attractiveness<<", ";
        cout<<enclosure_number<<"\n";
    }
};

class guest
{
private:
    string current_position;
public:
};

int main()
{
    animal a2;
    animal a("lion", "great", 2, 3, 1, 1, 97, 2);
    a.afisare_informatii();
}

