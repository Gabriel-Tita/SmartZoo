#include <iostream>
#include <string>
#include "Guest.cpp"
using namespace std;

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

    list.query_add_animal(creatures, "Lion", "Male");
    cout<<list;
    creatures.print_info();

    guest.calculate_rating(creatures);

    guest.calculate_number_of_free_empty_spaces();

    guest.guest_incoming(wallet, 100, list);
    cout<<wallet;
    guest.calculate_number_of_free_empty_spaces();
    return 0;
}