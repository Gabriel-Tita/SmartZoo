#pragma once
#include "ListOfEnclosures.hpp"
#include "Money.hpp"
#include "CounterMap.hpp"
#include "CounterMap.hpp"
#include "Utils.hpp"

/**
 * @class Guest
 * @brief Stores information about zoo visitors.
 *
 * Keeps track of guest positions (which enclosure they visit) and whether they came by car.
 * Also computes simple statistics like ratings and parking availability.
 */
class Guest {
    //clasa care retine informatii cu privire la vizitatori
private:
    /** @brief Cost charged when parking is not free. */
    int amountPerParkingSpace = -1;
    /** @brief Number of free parking spaces available. */
    int freeParkingSpaces = -1;
    /** @brief Number of paying parking spaces available. */
    int payingParkingSpaces = -1;
    /** @brief Species/enclosure name visited by each guest. */
    vector<string> position;
    /** @brief For each guest: true if they came by car. */
    vector<bool> car;
    /** @brief Current number of guests stored. */
    int number = -1;

    /** @brief Increases the internal guest counter. */
    void setNumber();

    /**
     * @brief Assigns a guest position based on an enclosure index.
     * @param list List of enclosures.
     * @param num Index used to choose an enclosure.
     */
    void setPosition(const ListOfEnclosures &list, int num);

    /**
     * @brief Stores if the guest came by car.
     * @param num 0 (no car) or 1 (car).
     */
    void setParkingLot(int num);

public:
    /** @brief Default constructor. */
    Guest() = default;

    /**
     * @brief Constructor with parking configuration.
     */
    Guest(int amountPerParkingSpace, int freeParkingSpaces, int payingParkingSpaces,
          int number);

    /** @brief Destructor. */
    ~Guest() = default;

    /**
     * @brief Generates a set of guests and assigns them to enclosures.
     * @param list List of enclosures used for assigning positions.
     */
    void generateGuests(const ListOfEnclosures &list);

    /** @brief Returns the list of visited enclosure/species names. */
    const vector<string> &getPositions() const { return position; }

    /** @brief Output operator for printing guests and their positions. */
    friend ostream &operator<<(ostream &os, const Guest &guest);

    /**
     * @brief Calculates a rating based on visitors and animal info from the zoo.
     * @param creatures Zoo containing animal information.
     */
    void calculateRating(const Zoo &creatures) const;

    /** @brief Prints how many free parking spaces are available. */
    void calculateNumberOfFreeEmptySpaces() const;

    /** @brief Returns the number of free parking spaces (can be negative). */
    int returnNumberOfFreeEmptySpaces() const;

    /**
     * @brief Adds new incoming guests and updates the wallet if parking is full.
     * @param wallet Money object where parking payments are added.
     * @param people Number of new guests.
     * @param list List of enclosures used for assigning positions.
     */
    void guestIncoming(Money &wallet, int people, const ListOfEnclosures &list);
};
