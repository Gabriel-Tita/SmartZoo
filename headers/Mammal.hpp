#pragma once
#include "Animal.hpp"

class Mammal : public Animal {
private:
    bool hasFur = 0;

protected:
    void doPrintInfo() const override;

public:
    Mammal() = default;

    Mammal(const string &speciesName, const string &health, int number, int viewingPlatform,
           int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
           bool hasFur);

    Mammal(const Mammal &other);

    Mammal &operator=(const Mammal &other);

    ~Mammal() override = default;

    virtual Animal *clone() const override = 0;

    virtual void makeSound() const override = 0;

    void printDetails(ostream &os) const override;

    bool getHasFur() const;

    void swapp(Mammal &other);
};
