#include "Guest.hpp"
//clasa care retine informatii cu privire la vizitatori
void Guest::set_number() {
    number++;
}

void Guest::set_position(const list_of_enclosures &list, const int num) {
    position.push_back(list.get_enclosure_species(num));
}

void Guest::set_parking_lot(const int num) {
    car.push_back((bool) num);
}

Guest::Guest(const int amount_per_parking_space, const int free_parking_spaces, const int paying_parking_spaces,
             const int number) {
    this->amount_per_parking_space = amount_per_parking_space;
    this->free_parking_spaces = free_parking_spaces;
    this->paying_parking_spaces = paying_parking_spaces;
    this->number = number;
}

void Guest::generate_guests(const list_of_enclosures &list) {
    int number_of_enclosures = list.get_number_of_enclosures();
    for (int i = 0; i < 100; i++) {
        set_position(list, i % number_of_enclosures);
        set_parking_lot(i % 2);
        set_number();
    }
}

ostream &operator<<(ostream &os, const Guest &guest) {
    os << "This is the list with the location of each guest!" << "\n";
    for (int i = 0; i < guest.number; i++) {
        os << "Guest number " << i + 1 << " is at the " << guest.position[i] << " enclosure";
        if (guest.car[i] == 0) {
            os << " and it didn't come with a car" << "\n";
        } else {
            os << " and it came with a car" << "\n";
        }
    }
    os << "\n";
    return os;
}

void Guest::calculate_rating(zoo &creatures) {
    int maximum_rating = 0;
    vector<string> verified_creatures;
    string winner_name;
    for (int i = 0; i < number; i++) {
        int already_verified = 0;
        for (int j = 0; j < (int) verified_creatures.size(); j++) {
            if (verified_creatures[j] == position[i]) {
                already_verified = 1;
                break;
            }
        }
        if (already_verified == 0) {
            //am gasit un animal pentru care nu am calculat ratingul
            verified_creatures.push_back(position[i]);
            int number_of_guests_visiting_the_animal = 0;
            for (int j = 0; j < number; j++) {
                if (position[i] == position[j]) {
                    number_of_guests_visiting_the_animal++;
                }
            }
            int current_rating = creatures.get_info(position[i]);
            current_rating = current_rating * number_of_guests_visiting_the_animal;
            if (current_rating > maximum_rating) {
                maximum_rating = current_rating;
                winner_name = position[i];
            }
        }
    }
    cout << "The creature that is the highest rated in the zoo is the " << winner_name << " " << "with a rating of " <<
            maximum_rating << "!\n\n";
}

void Guest::calculate_number_of_free_empty_spaces() {
    int occupied_spaces = 0;
    for (int i = 0; i < number; i++) {
        if (car[i] == 1) {
            occupied_spaces++;
        }
    }
    if (free_parking_spaces - occupied_spaces > 0) {
        cout << "Number of free empty spaces is " << free_parking_spaces - occupied_spaces << "\n\n";
    } else
        cout << "The are no free empty spaces!\n\n";
}

int Guest::return_number_of_free_empty_spaces() {
    int occupied_spaces = 0;
    for (int i = 0; i < number; i++) {
        if (car[i] == 1) {
            occupied_spaces++;
        }
    }
    return free_parking_spaces - occupied_spaces;
}

void Guest::guest_incoming(money &wallet, const int people, const list_of_enclosures &list) {
    int number_of_enclosures = list.get_number_of_enclosures();
    for (int i = 0; i < people; i++) {
        if (return_number_of_free_empty_spaces() <= 0) {
            wallet.set_wallet(amount_per_parking_space);
        }
        set_position(list, i % number_of_enclosures);
        set_parking_lot(1);
        set_number();
    }
}
