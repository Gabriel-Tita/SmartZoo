#pragma once
#include "Birds.hpp"

class Eagle : public Birds, public Treatment {
public:
    double wingspan = -1;

protected:
    void doPrintInfo() const override;

public:
    Eagle() = default;

    Eagle(const string &speciesName, const string &health, int number, int viewingPlatform,
          int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
          bool canFly, double wingspan);

    Eagle(const Eagle &other);

    Eagle &operator=(const Eagle &other);

    ~Eagle() override = default;

    void makeSound() const override;

    void applyTreatment(std::ostream& os) const override;

    Animal *clone() const override;

    double getWingspan() const;

    void interestingFacts() const;

    void printDetails(ostream &os) const override;
};
