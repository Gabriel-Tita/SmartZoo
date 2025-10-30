#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

class list_of_enclosures {
private:
    int number;
    vector<string> name;

    void update_number() {
        number++;
    }
public:
    list_of_enclosures()=default;

    list_of_enclosures(const int number) {
        this->number=number;
    }

    ~list_of_enclosures()=default;

    void set_enclosure(const string& name) {
        this->name.push_back(name);
        update_number();
    }

    void afisare_informatii() {
        for (int i=0;i<number;i++) {
            cout<<i<<" "<<name[i]<<" ";
        }
    }
};

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

    ~enclosure()=default;

    void afisare_informatii() {
        cout<<species<<", ";
        cout<<number_of_animals<<", ";
        cout<<number_of_enclosures<<"\n";
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

    ~animal()=default;

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
    list_of_enclosures list(0);
    animal lion("lion", "great", 2, 3, 1, 1, 97, 2);
    enclosure lion_enclosure("lion", 4, 1);
    list.set_enclosure("lion");
    lion.afisare_informatii();
    lion_enclosure.afisare_informatii();
    list.afisare_informatii();
    //generam 100 de vizitatori
    /**
    vector <guest> guests[100];
    for (int i=0;i<99;i++)
    {
        guests[i]=rand()%4;
    }**/
}

