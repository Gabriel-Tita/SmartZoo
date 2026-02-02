#pragma once
#include "Animal.hpp"

class Reptile : public Animal {
private:
    bool coldBlooded = 0;

protected:
    void doPrintInfo() const override;

public:
    Reptile() = default;

    Reptile(const string &speciesName, const string &health, int number, int viewingPlatform,
            int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
            bool coldBlooded);

    Reptile(const Reptile &other);

    Reptile &operator=(const Reptile &other);

    ~Reptile() override = default;

    virtual Animal *clone() const override = 0;

    virtual void makeSound() const override = 0;

    void printDetails(ostream &os) const override;

    bool isColdBlooded() const;
};
