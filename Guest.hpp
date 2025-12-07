#pragma once
#include "list_of_enclosures.hpp"
#include "money.hpp"

class Guest {
    //clasa care retine informatii cu privire la vizitatori
private:
    int amount_per_parking_space=-1;
    int free_parking_spaces=-1;
    int paying_parking_spaces=-1;
    vector <string> position;
    vector <bool> car;
    int number=-1;

    void set_number();

    void set_position(const list_of_enclosures& list, const int num);

    void set_parking_lot(const int num);

public:
    Guest()=default;

    Guest(const int amount_per_parking_space, const int free_parking_spaces, const int paying_parking_spaces, const int number);

    ~Guest()=default;

    void generate_guests(const list_of_enclosures& list);

    friend ostream& operator<<(ostream& os, const Guest& guest);

    void calculate_rating(zoo& creatures);

    void calculate_number_of_free_empty_spaces();

    int return_number_of_free_empty_spaces();

    void guest_incoming(money& wallet, const int people, const list_of_enclosures& list);
};