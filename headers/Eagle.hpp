#pragma once
#include "Birds.hpp"

/**
 * @class Eagle
 * @brief Represents an eagle species.
 *
 * Extends Birds with a wingspan attribute and supports medical treatment.
 */
class Eagle : public Birds, public Treatment {
public:
    /** @brief Wingspan of the eagle (in meters). */
    double wingspan = -1;

protected:
    /** @brief Prints eagle-specific information. */
    void doPrintInfo() const override;

public:
    /** @brief Default constructor. */
    Eagle() = default;

    /**
     * @brief Constructor with all attributes.
     */
    Eagle(const string &speciesName, const string &health, int number, int viewingPlatform,
          int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
          bool canFly, double wingspan);

    /** @brief Copy constructor. */
    Eagle(const Eagle &other);

    /** @brief Copy assignment operator. */
    Eagle &operator=(const Eagle &other);

    /** @brief Virtual destructor. */
    ~Eagle() override = default;

    /** @brief Makes the eagle produce a sound. */
    void makeSound() const override;

    /** @brief Applies a medical treatment to the eagle. */
    void applyTreatment(std::ostream& os) const override;

    /**
     * @brief Polymorphic copy of the eagle.
     * @return Pointer to a cloned object.
     */
    Animal *clone() const override;

    /** @brief Returns the eagle's wingspan. */
    double getWingspan() const;

    /** @brief Prints some interesting facts about the eagle. */
    void interestingFacts() const;

    /** @brief Prints detailed information about the eagle. */
    void printDetails(ostream &os) const override;
};
