#pragma once
#include "ListOfEnclosures.hpp"
#include "Money.hpp"
#include "CounterMap.hpp"
#include "CounterMap.hpp"
#include "Utils.hpp"

class Guest {
    //clasa care retine informatii cu privire la vizitatori
private:
    int amountPerParkingSpace = -1;
    int freeParkingSpaces = -1;
    int payingParkingSpaces = -1;
    vector<string> position;
    vector<bool> car;
    int number = -1;

    void setNumber();

    void setPosition(const ListOfEnclosures &list, int num);

    void setParkingLot(int num);

public:
    Guest() = default;

    Guest(int amountPerParkingSpace, int freeParkingSpaces, int payingParkingSpaces,
          int number);

    ~Guest() = default;

    void generateGuests(const ListOfEnclosures &list);

    const vector<string>& getPositions() const { return position; }

    friend ostream &operator<<(ostream &os, const Guest &guest);

    void calculateRating(const Zoo &creatures) const;

    void calculateNumberOfFreeEmptySpaces() const;

    int returnNumberOfFreeEmptySpaces() const;

    void guestIncoming(Money &wallet, int people, const ListOfEnclosures &list);
};
