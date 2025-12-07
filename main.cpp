#include <iostream>
#include <string>
#include "Guest.hpp"
#include "mammal.hpp"
#include "birds.hpp"
#include "eagle.hpp"
#include "lion.hpp"
#include "Reptile.hpp"
#include "snake.hpp"
using namespace std;

int main() {
    list_of_enclosures list(0);
    money wallet(0);
    Guest guest(10, 100, 100, 0);


    zoo my_smart_zoo;
    lion lion1("Lion", "Good", 2, 1, 1, 1, 80, 1, true, "Golden");
    snake snake1("Python", "Fair", 1, 0, 0, 1, 60, 1, false, false);
    eagle eagle1("Golden Eagle", "Excellent", 3, 2, 2, 1, 95, 1, true, 2.0);
    my_smart_zoo.add(lion1);
    my_smart_zoo.add(snake1);
    my_smart_zoo.add(eagle1);
    my_smart_zoo.daily_feed_and_sound();


    enclosure lion_enclosure("Lion", 4, 1, 2);
    enclosure snake_enclosure("Snake", 5, 1, 2);
    enclosure eagle_enclosure("Eagle", 6, 1, 2);
    list.add(lion_enclosure);
    list.add(snake_enclosure);
    list.add(eagle_enclosure);


    lion lion2("Lion", "Good", 2, 1, 1, 1, 80, 1, true, "Golden");
    enclosure lion2_enclosure("Lion", 4, 1, 2);
    lion2.print_info();
    lion2_enclosure.print_info();
    list.print_info();

    lion lion3=lion2;
    lion lion4;
    lion4=lion3;
    lion3.print_info();
    cout<<lion4;

    guest.generate_guests(list);
    cout<<guest;
    list.query_add_animal(my_smart_zoo, "Lion", "Male");
    cout<<list;

    guest.calculate_rating(my_smart_zoo);
    guest.calculate_number_of_free_empty_spaces();
    guest.guest_incoming(wallet, 100, list);
    cout<<wallet;
    guest.calculate_number_of_free_empty_spaces();

    cout<<eagle1;
    cout<<snake1;
    cout<<lion1;



    return 0;
}