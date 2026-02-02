#pragma once
#include "Reptile.hpp"

class Crocodile : public Reptile {
private:
    bool livesInSaltyWaters = 0;

protected:
    void doPrintInfo() const override;

public:
    Crocodile() = default;

    Crocodile(const string &speciesName, const string &health, int number, int viewingPlatform,
              int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
              bool coldBlooded, bool livesInSaltyWaters);

    Crocodile(const Crocodile &other);

    Crocodile &operator=(const Crocodile &other);

    ~Crocodile() override = default;

    void printDetails(ostream &os) const override;

    void makeSound() const override;

    Animal *clone() const override;

    bool getLivesInSaltyWaters() const;

    void interestingFacts() const;
};
