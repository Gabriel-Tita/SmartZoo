#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

class money{
private:
    int coins=-1;
public:
    money()=default;

    money(const int coins) {
        this->coins=coins;
    }

    int get_coins() const {
        return coins;
    }

    void set_wallet(const int amount_to_be_added) {
        coins+=amount_to_be_added;
    }

    ~money()=default;

    friend ostream& operator<<(ostream& os, const money money) {
        os<<"The budget of the zoo is "<<money.coins<<"!\n\n";
        return os;
    }
};

class enclosure
{
    // clasa care retine informatii despre tarcurile fiecarei specii
private:
    string species="Unknown";
    int number_of_animals=-1, number_of_enclosures=-1, current_animal_number=-1;
public:
    enclosure()=default;

    enclosure(const string& species, const int number_of_animals, const int number_of_enclosures, const int current_animal_number) {
        this->species=species;
        this->number_of_animals=number_of_animals;
        this->number_of_enclosures=number_of_enclosures;
        this->current_animal_number=current_animal_number;
    }

    ~enclosure()=default;

    const string& get_species() const {
        return species;
    }

    int get_number_of_animals() {
        return number_of_animals;
    }

    int get_current_animals_number() const {
        return current_animal_number;
    }

    void print_info() {
        cout<<"This is everything about the enclosures of the ";
        cout<<species<<"!\n";
        cout<<"The number of animals that can coexist in one single enclosure: "<<number_of_animals<<"\n";
        cout<<"The number of enclosures for this species that we currently have: "<<number_of_enclosures<<"\n";
        cout<<"The number of animals that are right now in the enclosure: "<<current_animal_number<<"\n\n";
    }

    friend ostream& operator<<(ostream& os, const enclosure& enclosure) {
        os<<"This is everything about the enclosures of the ";
        os<<enclosure.species<<"!\n";
        os<<"The number of animals that can coexist in one single enclosure: "<<enclosure.number_of_animals<<"\n";
        os<<"The number of enclosures for this species that we currently have: "<<enclosure.number_of_enclosures<<"\n";
        os<<"The number of animals that are right now in the enclosure: "<<enclosure.current_animal_number<<"\n\n";
        return os;
    }

    void add_one_animal() {
        current_animal_number++;
    }
};

class animal
{
    //clasa care retine informatii despre fiecare specie din parc
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

    //contructor de copiere
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

    //operator egal (de atribuire)
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

    const string& get_species () const {
        return species_name;
    }

    void update_gender_of_creatures(const string& gender){
        number++;
        if (gender=="Male") {
            male_number++;
        }
        else {
            female_number++;
        }
    }

    int get_more_info() {
        return number*attractiveness;
    }

};

class zoo {
    //clasa care retine informatii generale despre fiecare specie din tarc(utila pentru ca putem cauta
    //mult mai usor informatii despre fiecare creatura utilizand NUMELE ei)
private:
    int number=-1;
    vector<animal> animals;
public:

    zoo()=default;

    explicit zoo(const int number) {
        this->number=number;
    }

    ~zoo()=default;

    friend ostream& operator<<(ostream& os, const zoo& zoo) {
        os<<"This is a list with all the creatures that we have!\n";
        for(int i=0;i<zoo.number;i++) {
            os<<"Creature number "<<i+1<<" : "<<zoo.animals[i].get_species()<<"\n";
        }
        os<<"\n";
        return os;
    }

    void print_info() {
        cout<<"This is a list with all the creatures that we have and the information about them:\n";
        for (int i=0;i<number;i++) {
            cout<<animals[i];
        }
    }

    void add(const animal& animal) {
        animals.push_back(animal);
        number++;
    }

    void add_individual(const string& name, const string& gender) {
        for (int i=0;i<number;i++) {
            if (name==animals[i].get_species()) {
                animals[i].update_gender_of_creatures(gender);
                return;
            }
        }
    }

    int get_info(const string& name) {
        for (int i=0;i<number;i++) {
            if (name==animals[i].get_species()) {
                return animals[i].get_more_info();
            }
        }
        return 0;
    }

};

class list_of_enclosures {
private:
    // clasa care retine cate tarcuri avem pentru fiecare specie
    int number=-1;
    vector<enclosure> enc;

public:
    list_of_enclosures()=default;

    explicit list_of_enclosures(const int number) {
        this->number=number;
    }

    ~list_of_enclosures()=default;

    int get_number_of_enclosures() const{
        return number;
    }

    const string& get_enclosure_species(const int num) const {
        return enc[num].get_species();
    }

    void add(const enclosure& Enclosure) {
        enc.push_back(Enclosure);
        number++;
    }

    void query_add_animal(zoo& species, const string& name, const string& gender) {
        for (int i=0;i<number;i++) {
            if (name==enc[i].get_species()) {
                if (enc[i].get_current_animals_number()<enc[i].get_number_of_animals()) {
                    enc[i].add_one_animal();
                    cout<<"We added the creature in the enclosure number "<<i+1<<".\n\n";
                    species.add_individual(name, gender);
                    return;
                }
            }
        }
        cout<<"We couldn't add the creature in any enclosure.\n";
    }

    void print_info() {
        cout<<"This is a list of all the enclosures that we currently have: "<<"\n";
        for (int i=0;i<number;i++) {
            cout<<"Number "<<i+1<<": "<<"\n"<<enc[i];
        }
    }

    friend ostream& operator<<(ostream& os, const list_of_enclosures& list_of_enclosures) {
        os<<"This is a list of all the enclosures that we currently have: "<<"\n";
        for (int i=0;i<list_of_enclosures.number;i++) {
            os<<"Number "<<i+1<<": "<<"\n"<<list_of_enclosures.enc[i];
        }
        return os;
    }
};

class Guest
{
    //clasa care retine informatii cu privire la vizitatori
private:
    int amount_per_parking_space=-1;
    int free_parking_spaces=-1;
    int paying_parking_spaces=-1;
    vector <string> position;
    vector <bool> car;
    int number=-1;

    void set_number() {
        number++;
    }

    void set_position(const list_of_enclosures& list, const int num) {
        position.push_back(list.get_enclosure_species(num));
    }

    void set_parking_lot(const int num) {
        car.push_back((bool)num);
    }

public:
    Guest()=default;

    explicit Guest(const int amount_per_parking_space, const int free_parking_spaces, const int paying_parking_spaces, const int number) {
        this->amount_per_parking_space=amount_per_parking_space;
        this->free_parking_spaces=free_parking_spaces;
        this->paying_parking_spaces=paying_parking_spaces;
        this->number=number;
    }

    ~Guest()=default;

    void generate_guests(const list_of_enclosures& list){
        int number_of_enclosures=list.get_number_of_enclosures();
        for (int i=0;i<100;i++) {
            set_position(list, i%number_of_enclosures);
            set_parking_lot(i%2);
            set_number();
        }
    }

    friend ostream& operator<<(ostream& os, const Guest& guest) {
        os<<"This is the list with the location of each guest!"<<"\n";
        for (int i=0;i<guest.number;i++) {
            os<<"Guest number "<<i+1<<" is at the "<<guest.position[i]<<" enclosure";
            if (guest.car[i]==0) {
                os<<" and it didn't come with a car"<<"\n";
            }
            else {
                os<<" and it came with a car"<<"\n";
            }
        }
        os<<"\n";
        return os;
    }

    void calculate_rating(zoo& creatures) {
        int maximum_rating=0;
        vector<string> verified_creatures;
        string winner_name;
        for (int i=0;i<number;i++) {
            int already_verified=0;
            for (int j=0;j<(int)verified_creatures.size();j++) {
                if (verified_creatures[j]==position[i]) {
                    already_verified=1;
                    break;
                }
            }
            if (already_verified==0) {
                //am gasit un animal pentru care nu am calculat ratingul
                verified_creatures.push_back(position[i]);
                int number_of_guests_visiting_the_animal=0;
                for (int j=0;j<number;j++) {
                    if (position[i]==position[j]) {
                        number_of_guests_visiting_the_animal++;
                    }
                }
                int current_rating=creatures.get_info(position[i]);
                current_rating=current_rating*number_of_guests_visiting_the_animal;
                if (current_rating>maximum_rating) {
                    maximum_rating=current_rating;
                    winner_name=position[i];
                }
            }
        }
        cout<<"The creature that is the highest rated in the zoo is the "<<winner_name<<" "<<"with a rating of "<<maximum_rating<<"!\n\n";
    }

    void calculate_number_of_free_empty_spaces() {
        int occupied_spaces=0;
        for (int i=0;i<number;i++) {
            if (car[i]==1) {
                occupied_spaces++;
            }
        }
        if (free_parking_spaces-occupied_spaces>0) {
            cout<<"Number of free empty spaces is "<<free_parking_spaces-occupied_spaces<<"\n\n";
        }
        else
            cout<<"The are no free empty spaces!\n\n";
    }

    int return_number_of_free_empty_spaces() {
        int occupied_spaces=0;
        for (int i=0;i<number;i++) {
            if (car[i]==1) {
                occupied_spaces++;
            }
        }
        return free_parking_spaces-occupied_spaces;
    }

    void guest_incoming(money& wallet, const int people, const list_of_enclosures& list) {
        int number_of_enclosures=list.get_number_of_enclosures();
        for (int i=0;i<people;i++) {
            if (return_number_of_free_empty_spaces()<=0) {
                wallet.set_wallet(amount_per_parking_space);
            }
            set_position(list, i%number_of_enclosures);
            set_parking_lot(1);
            set_number();
        }
    }
};

int main()
{
    list_of_enclosures list(0);
    Guest guest(10, 100, 100, 0);
    zoo creatures(0);
    money wallet(0);

    animal lion("Lion", "great", 2, 3, 1, 1, 84, 1);
    creatures.add(lion);
    enclosure lion_enclosure("Lion", 4, 1, 2);
    list.add(lion_enclosure);

    // pentru a pune in valoare functiile de afisare
    lion.print_info();
    lion_enclosure.print_info();
    list.print_info();

    animal tiger("Tiger", "great", 1, 3, 1, 0, 87, 1);
    creatures.add(tiger);
    enclosure tiger_enclosure("Tiger", 2, 1, 1);
    list.add(tiger_enclosure);

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

    animal zebra("Zebra", "good", 6, 2, 2, 4, 68, 1);
    creatures.add(zebra);
    enclosure zebra_enclosure("Zebra", 10, 1, 6);
    list.add(zebra_enclosure);

    //punem in valoare operatorul << pentru clasa guest
    guest.generate_guests(list);
    cout<<guest;

    cout<<creatures;

    //interogare cu privire la ce animal dintre cele pe care le avem sa mai aducem la zoo si afisare
    //a modificarilor corespunzatoare(o functie care apeleaza 6 sau 7 functii).
    list.query_add_animal(creatures, "Lion", "Male");
    cout<<list;
    creatures.print_info();

    guest.calculate_rating(creatures);

    guest.calculate_number_of_free_empty_spaces();

    //de facut o functie care mai aduce 100 de invitati, toti cu masina. ii primim pe primii, restul sunt
    //platesc o suma de bani, si mai definesc un camp parcare cu plata.

    guest.guest_incoming(wallet, 100, list);
    cout<<wallet;
    guest.calculate_number_of_free_empty_spaces();
}



