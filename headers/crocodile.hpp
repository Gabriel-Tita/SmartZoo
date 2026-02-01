#pragma once
#include "Reptile.hpp"

class crocodile : public reptile {
private:
    bool lives_in_salty_waters = 0;

protected:
    void do_print_info() const override;

public:
    crocodile() = default;

    crocodile(const string &species_name, const string &health, const int number, const int viewing_platform,
              const int male_number, const int female_number, const int attractiveness, const int enclosure_number,
              const bool cold_blooded, const bool lives_in_salty_waters);

    crocodile(const crocodile &other);

    crocodile &operator=(const crocodile &other);

    ~crocodile() override = default;

    void print_details(ostream &os) const override;

    void make_sound() const override;

    animal *clone() const override;

    bool get_lives_in_salty_waters() const;

    void interesting_facts() const;
};
