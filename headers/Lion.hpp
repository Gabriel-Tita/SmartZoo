#pragma once
#include "Mammal.hpp"
#include "Treatment.hpp"

/**
 * @class Lion
 * @brief Represents a lion species.
 *
 * Extends Mammal with information about mane colour and supports treatment.
 */
class Lion : public Mammal , public Treatment {
private:
    /** @brief Colour of the lion's mane. */
    string maneColour = "Unknown";

protected:
    /** @brief Prints lion-specific information. */
    void doPrintInfo() const override;

public:
    /** @brief Default constructor. */
    Lion() = default;

    /**
     * @brief Constructor with all attributes.
     */
    Lion(const string &speciesName, const string &health, int number, int viewingPlatform,
         int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
         bool hasFur, const string &maneColour);

    /** @brief Copy constructor. */
    Lion(const Lion &other);

    /** @brief Copy assignment operator. */
    Lion &operator=(const Lion &other);

    /** @brief Virtual destructor. */
    ~Lion() override = default;

    /** @brief Prints detailed information about the lion. */
    void printDetails(ostream &os) const override;

    /** @brief Makes the lion produce a sound. */
    void makeSound() const override;

    /** @brief Applies a medical treatment to the lion. */
    void applyTreatment(ostream& os) const override;

    /**
     * @brief Polymorphic copy of the lion.
     * @return Pointer to a cloned object.
     */
    Animal *clone() const override;

    /** @brief Returns the mane colour. */
    const string &getManeColour() const;

    /** @brief Prints some interesting facts about the lion. */
    void interestingFacts() const;

    /**
     * @brief Swaps this lion with another one.
     * @param other Another lion object.
     */
    void swapp(Lion &other);
};
