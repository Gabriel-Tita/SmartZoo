#pragma once
#include "animal.hpp"
#include "Tratament.hpp"

class birds : public animal{
private:
    bool can_fly = 0;

protected:
    void do_print_info() const override;

public:
    birds() = default;

    birds(const string &species_name, const string &health, const int number, const int viewing_platform,
          const int male_number, const int female_number, const int attractiveness, const int enclosure_number,
          bool can_fly);

    birds(const birds &other);

    birds &operator=(const birds &other);

    ~birds() override = default;

    virtual animal *clone() const override =0;

    virtual void make_sound() const override =0;

    void print_details(ostream &os) const override;

    bool get_can_fly() const;
};
