#pragma once
#include "Mammal.hpp"
#include "Treatment.hpp"

class Lion : public Mammal , public Treatment {
private:
    string maneColour = "Unknown";

protected:
    void doPrintInfo() const override;

public:
    Lion() = default;

    Lion(const string &speciesName, const string &health, int number, int viewingPlatform,
         int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
         bool hasFur, const string &maneColour);

    Lion(const Lion &other);

    Lion &operator=(const Lion &other);

    ~Lion() override = default;

    void printDetails(ostream &os) const override;

    void makeSound() const override;

    void applyTreatment(ostream& os) const override;

    Animal *clone() const override;

    const string &getManeColour() const;

    void interestingFacts() const;

    void swapp(Lion &other);
};
