#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

class list_of_enclosures {
private:
    int number=-1;
    vector<string> name;

    void set_number() {
        number++;
    }

    void set_name(const string& Name) {
        this->name.push_back(Name);
    }
public:
    list_of_enclosures()=default;

    explicit list_of_enclosures(const int number) {
        this->number=number;
    }

    ~list_of_enclosures()=default;

    void set_enclosure(const string& Name) {
        set_name(Name);
        set_number();
    }

    int get_number_of_enclosures() const{
        return number;
    }

    string get_enclosure_species(const int num) const {
        return name[num];
    }

    void print_info() {
        cout<<"This is a list of all the enclosures that we currently have: "<<"\n";
        for (int i=0;i<number;i++) {
            cout<<"Number "<<i+1<<": "<<name[i]<<"\n";
        }
        cout<<"\n";
    }

    friend ostream& operator<<(ostream& os, const list_of_enclosures& list_of_enclosures) {
        os<<"This is a list of all the enclosures that we currently have: "<<"\n";
        for (int i=0;i<list_of_enclosures.number;i++) {
            os<<"Number "<<i+1<<": "<<list_of_enclosures.name[i]<<"\n";
        }
        os<<"\n";
        return os;
    }
};

class enclosure
{
private:
    string species="Unknown";
    int number_of_animals=-1, number_of_enclosures=-1;
public:
    enclosure()=default;

    enclosure(const string& species, const int number_of_animals, const int number_of_enclosures) {
        this->species=species;
        this->number_of_animals=number_of_animals;
        this->number_of_enclosures=number_of_enclosures;
    }

    ~enclosure()=default;

    void print_info() {
        cout<<"This is everything about the enclosures of the ";
        cout<<species<<"!\n";
        cout<<"The number of animals that can coexist in one single enclosure: "<<number_of_animals<<"\n";
        cout<<"The number of enclosures for this species that we currently have: "<<number_of_enclosures<<"\n\n";
    }

    friend ostream& operator<<(ostream& os, const enclosure& enclosure) {
        os<<"This is everything about the enclosures of the ";
        os<<enclosure.species<<"!\n";
        os<<"The number of animals that can coexist in one single enclosure: "<<enclosure.number_of_animals<<"\n";
        os<<"The number of enclosures for this species that we currently have: "<<enclosure.number_of_enclosures<<"\n\n";
        return os;
    }
};

class animal
{
private:
    string species_name="Unknown", health="Unknown";
    int number=-1, viewing_platform=-1, male_number=-1, female_number=-1, attractiveness=-1, enclosure_number=-1;
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
        cout<<"This is the end of the program!\n";
    }

    friend ostream& operator<<(ostream& os, const animal& animal) {
        os<<"This is what we know about the next animal!"<<"\n";
        os<<"Species: "<<animal.species_name<<"\n";
        os<<"The Health of the animals: "<<animal.health<<"\n";
        os<<"The number of animals: "<<animal.number<<"\n";
        os<<"The number of viewing platforms: "<<animal.viewing_platform<<"\n";
        os<<"The number of males: "<<animal.male_number<<"\n";
        os<<"The number of females: "<<animal.female_number<<"\n";
        os<<"The attractiveness (a number based on how rare this animal is): "<<animal.attractiveness<<"\n";
        os<<"The number of enclosures in which this creature lives: "<<animal.enclosure_number<<"\n\n";
        return os;
    }

    void print_info()
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
    int number=-1;

    void set_number() {
        number++;
    }

    void set_position(const list_of_enclosures& list, const int num) {
        position.push_back(list.get_enclosure_species(num));
    }

public:
    Guest()=default;

    explicit Guest(const int number) {
        this->number=number;
    }

    ~Guest()=default;

    void generate_guests(const list_of_enclosures& list){
        int number_of_enclosures=list.get_number_of_enclosures();
        for (int i=0;i<100;i++) {
            set_position(list, i%number_of_enclosures);
            set_number();
        }
    }

    friend ostream& operator<<(ostream& os, const Guest& guest) {
        os<<"This is the list with the location of each guest!"<<"\n";
        for (int i=0;i<guest.number;i++) {
            os<<"Guest number "<<i+1<<" is at the "<<guest.position[i]<<" enclosure"<<"\n";
        }
        os<<"\n";
        return os;
    }
};

int main()
{
    list_of_enclosures list(0);
    Guest guest(0);

    // Am  adaugat 2 specii: leu si tigru
    animal lion("Lion", "great", 2, 3, 1, 1, 84, 1);
    enclosure lion_enclosure("Lion", 4, 1);
    list.set_enclosure("Lion");

    // pentru a pune in valoare functiile de afisare
    lion.print_info();
    lion_enclosure.print_info();
    list.print_info();

    enclosure tiger_enclosure("Tiger", 2, 1);
    animal tiger("Tiger", "great", 1, 3, 1, 0, 87, 1);
    list.set_enclosure("Tiger");

    animal lion2=lion;
    animal lion3;
    lion3=lion;

    //pentru a pune in valoare constructorul de copiere si operatorul de copiere
    lion2.print_info();
    lion3.print_info();

    //pentru a pune in valoare operatorul << pentru toate clasele
    cout<<tiger;
    cout<<tiger_enclosure;
    cout<<list;

    //punem in valoare operatorul << pentru clasa guest
    guest.generate_guests(list);
    cout<<guest;
}



