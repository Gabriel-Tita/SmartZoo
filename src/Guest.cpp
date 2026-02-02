#include "Guest.hpp"

//clasa care retine informatii cu privire la vizitatori

/** @brief Increases the internal guest counter. */
void Guest::setNumber() {
    number++;
}

/**
 * @brief Adds a position (enclosure species) for the next guest.
 */
void Guest::setPosition(const ListOfEnclosures &list, int num) {
    position.push_back(list.getEnclosureSpecies(num));
}

/**
 * @brief Stores whether the guest came by car (0/1).
 */
void Guest::setParkingLot(int num) {
    car.push_back((bool) num);
}

/**
 * @brief Constructs a Guest manager with parking settings.
 */
Guest::Guest(int amountPerParkingSpace, int freeParkingSpaces, int payingParkingSpaces,
             int number) {
    this->amountPerParkingSpace = amountPerParkingSpace;
    this->freeParkingSpaces = freeParkingSpaces;
    this->payingParkingSpaces = payingParkingSpaces;
    this->number = number;
}

/**
 * @brief Generates guests, assigns positions, and prints a small car histogram.
 */
void Guest::generateGuests(const ListOfEnclosures &list) {
    int numberOfEnclosures = list.getNumberOfEnclosures();

    CounterMap<int> carCount; // 0 = fara masina, 1 = cu masina

    for (int i = 0; i < 100; i++) {
        int hasCar = i % 2;

        setPosition(list, i % numberOfEnclosures);
        setParkingLot(hasCar);
        setNumber();

        carCount.add(hasCar); // template class + colectare statistica
    }

    // template function - instantiere cu Key = int
    printHistogram(carCount, "Guests with car (1) vs without car (0)");
}

/**
 * @brief Prints all guests with their location and car status.
 */
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

/**
 * @brief Computes the highest rated animal based on number of visitors.
 */
void Guest::calculateRating(const Zoo &creatures) const {
    int maximumRating = 0;
    vector<string> verifiedCreatures;
    string winner_name;
    for (int i = 0; i < number; i++) {
        int alreadyVerified = 0;
        for (int j = 0; j < (int) verifiedCreatures.size(); j++) {
            if (verifiedCreatures[j] == position[i]) {
                alreadyVerified = 1;
                break;
            }
        }
        if (alreadyVerified == 0) {
            //am gasit un animal pentru care nu am calculat ratingul
            verifiedCreatures.push_back(position[i]);
            int numberOfGuestsVisitingTheAnimal = 0;
            for (int j = 0; j < number; j++) {
                if (position[i] == position[j]) {
                    numberOfGuestsVisitingTheAnimal++;
                }
            }
            int currentRating = creatures.getInfo(position[i]);
            currentRating = currentRating * numberOfGuestsVisitingTheAnimal;
            if (currentRating > maximumRating) {
                maximumRating = currentRating;
                winner_name = position[i];
            }
        }
    }
    cout << "The creature that is the highest rated in the zoo is the " << winner_name << " "
            << "with a rating of " << maximumRating << "!\n\n";
}

/**
 * @brief Prints the number of free parking spaces left.
 */
void Guest::calculateNumberOfFreeEmptySpaces() const {
    int occupiedSpaces = 0;
    for (int i = 0; i < number; i++) {
        if (car[i] == 1) {
            occupiedSpaces++;
        }
    }
    if (freeParkingSpaces - occupiedSpaces > 0) {
        cout << "Number of free empty spaces is " << freeParkingSpaces - occupiedSpaces << "\n\n";
    } else
        cout << "The are no free empty spaces!\n\n";
}

/**
 * @brief Returns the number of free parking spaces left.
 */
int Guest::returnNumberOfFreeEmptySpaces() const {
    int occupiedSpaces = 0;
    for (int i = 0; i < number; i++) {
        if (car[i] == 1) {
            occupiedSpaces++;
        }
    }
    return freeParkingSpaces - occupiedSpaces;
}

/**
 * @brief Adds incoming guests and charges for parking if no free spaces are left.
 */
void Guest::guestIncoming(Money &wallet, int people, const ListOfEnclosures &list) {
    int number_of_enclosures = list.getNumberOfEnclosures();
    for (int i = 0; i < people; i++) {
        if (returnNumberOfFreeEmptySpaces() <= 0) {
            wallet.setWallet(amountPerParkingSpace);
        }
        setPosition(list, i % number_of_enclosures);
        setParkingLot(1);
        setNumber();
    }
}
