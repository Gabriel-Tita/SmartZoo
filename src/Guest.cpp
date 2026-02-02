#include "Guest.hpp"

//clasa care retine informatii cu privire la vizitatori
void Guest::setNumber() {
    number++;
}

void Guest::setPosition(const ListOfEnclosures &list, int num) {
    position.push_back(list.getEnclosureSpecies(num));
}

void Guest::setParkingLot(int num) {
    car.push_back((bool) num);
}

Guest::Guest(int amountPerParkingSpace, int freeParkingSpaces, int payingParkingSpaces,
             int number) {
    this->amountPerParkingSpace = amountPerParkingSpace;
    this->freeParkingSpaces = freeParkingSpaces;
    this->payingParkingSpaces = payingParkingSpaces;
    this->number = number;
}

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

int Guest::returnNumberOfFreeEmptySpaces() const {
    int occupiedSpaces = 0;
    for (int i = 0; i < number; i++) {
        if (car[i] == 1) {
            occupiedSpaces++;
        }
    }
    return freeParkingSpaces - occupiedSpaces;
}

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
