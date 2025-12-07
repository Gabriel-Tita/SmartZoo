#pragma once
#include "mammal.hpp"

class lion : public mammal{
private:
    string mane_colour="Unknown";
protected:
    void do_print_info()const override;
public:
    lion()=default;
    lion(const string& species_name, const string& health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, const bool has_fur, const string& mane_colour);
    lion(const lion& other);
    lion& operator=(lion other);
    ~lion()override=default;

    void print_details(ostream& os)const override;

    void make_sound() const override;
    animal* clone()const override;
    const string& get_mane_colour()const;

    void interesting_facts() const;

    void swapp(lion& other);
};
