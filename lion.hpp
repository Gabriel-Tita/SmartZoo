#pragma once
#include "mammal.hpp"

class lion : public mammal{
private:
    string mane_colour="Unknown";
public:
    lion()=default;
    lion(const string& species_name, const string& health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, const bool has_fur, const string& mane_colour);
    lion(const lion& other);
    lion& operator=(const lion& other);
    ~lion()override=default;

    void print_details(ostream& os)const override;

    void make_sound() const override;
    animal* clone()const override;
    void print_info() override;
    const string& get_mane_colour()const;
};
