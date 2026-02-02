#pragma once
#include "Reptile.hpp"

class Snake : public Reptile {
private:
    bool isPoisonous = 0;

protected:
    void doPrintInfo() const override;

public:
    Snake() = default;

    Snake(const string &speciesName, const string &health, int number, int viewingPlatform,
          int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
          bool coldBlooded, bool isPoisonous);

    Snake(const Snake &other);

    Snake &operator=(const Snake &other);

    ~Snake() override = default;

    void printDetails(ostream &os) const override;

    void makeSound() const override;

    Animal *clone() const override;

    bool getIsPoisonous() const;

    void interestingFacts() const;
};
