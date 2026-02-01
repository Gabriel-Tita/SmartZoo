#pragma once
#include "birds.hpp"

class eagle : public birds {
public:
    double wingspan = -1;

protected:
    void do_print_info() const override;

public:
    eagle() = default;

    eagle(const string &species_name, const string &health, const int number, const int viewing_platform,
          const int male_number, const int female_number, const int attractiveness, const int enclosure_number,
          const bool can_fly, const double wingspan);

    eagle(const eagle &other);

    eagle &operator=(const eagle &other);

    ~eagle() override = default;

    void make_sound() const override;

    animal *clone() const override;

    double get_wingspan() const;

    void interesting_facts() const;

    void print_details(ostream &os) const override;
};
