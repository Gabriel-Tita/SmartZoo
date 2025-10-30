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
        cout<<"This is a list of all the enclosures that we currently have: "<<"\n";
        for (int i=0;i<number;i++) {
            cout<<"Number "<<i+1<<": "<<name[i]<<"\n";
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
        cout<<"This is everything about the enclosures of the ";
        cout<<species<<"!\n";
        cout<<"The number of animals that can coexist in one single enclosure: "<<number_of_animals<<"\n";
        cout<<"The number of enclosures for this species that we currently have: "<<number_of_enclosures<<"\n\n";
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

    animal(const animal& animal) {
        this->species_name=animal.species_name;
        this->health=animal.health;
        this->number=animal.number;
        this->viewing_platform=animal.viewing_platform;
        this->male_number=animal.male_number;
        this->female_number=animal.female_number;
        this->attractiveness=animal.attractiveness;
        this->enclosure_number=animal.enclosure_number;
    }

    animal& operator=(const animal& animal) {
        this->species_name=animal.species_name;
        this->health=animal.health;
        this->number=animal.number;
        this->viewing_platform=animal.viewing_platform;
        this->male_number=animal.male_number;
        this->female_number=animal.female_number;
        this->attractiveness=animal.attractiveness;
        this->enclosure_number=animal.enclosure_number;
        return *this;
    }

    ~animal() {
        cout<<"Finalul programului! Toata memoria s-a dezalocat cu succes!\n";
    }

    void afisare_informatii()
    {
        cout<<"This is what we know about the next animal!"<<"\n";
        cout<<"Species: "<<species_name<<"\n";
        cout<<"The Health of the animals: "<<health<<"\n";
        cout<<"The number of animals: "<<number<<"\n";
        cout<<"The number of viewing platforms: "<<viewing_platform<<"\n";
        cout<<"The number of males: "<<male_number<<"\n";
        cout<<"The number of females: "<<female_number<<"\n";
        cout<<"The attractiveness (a number based on how rare this animal is): "<<attractiveness<<"\n";
        cout<<"The number of enclosures in which this creature lives: "<<enclosure_number<<"\n\n";
    }
};

class Guest
{
private:
    vector <string> position;
    int number;
public:
    Guest()=default;

    Guest(const int number) {
        this->number=number;
    }

    ~Guest()=default;

    // void generate_guests() {
    //     for (int i=0;i<100;i++) {
    //
    //     }
    // }
};

int main()
{
    list_of_enclosures list(0);
    Guest guest(0);

    // Am  adaugat 2 specii: leu si tigru
    animal lion("Lion", "great", 2, 3, 1, 1, 84, 1);
    animal tiger("Tiger", "great", 1, 3, 1, 0, 87, 1);

    enclosure lion_enclosure("Lion", 4, 1);
    enclosure tiger_enclosure("Tiger", 2, 1);

    list.set_enclosure("Lion");
    list.set_enclosure("Tiger");

    animal lion2=lion;
    animal lion3;
    lion3=lion;


    //lion.afisare_informatii();
    //lion_enclosure.afisare_informatii();
    //list.afisare_informatii();
    //lion2.afisare_informatii();
    lion3.afisare_informatii();

    //generate_guests();
}

