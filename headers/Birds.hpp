#pragma once
#include "Animal.hpp"
#include "Treatment.hpp"

class Birds : public Animal {
private:
    bool canFly = 0;

protected:
    void doPrintInfo() const override;

public:
    Birds() = default;

    Birds(const string &speciesName, const string &health, int number, int viewingPlatform,
          int maleNumber, int femaleNumber, int attractiveness, int enclosureNumber,
          bool canFly);

    Birds(const Birds &other);

    Birds &operator=(const Birds &other);

    ~Birds() override = default;

    virtual Animal *clone() const override = 0;

    virtual void makeSound() const override = 0;

    void printDetails(ostream &os) const override;

    bool getCanFly() const;
};
