#pragma once
#include "Reptile.hpp"
class snake : public reptile {
private:
    bool is_poisonous=0;
protected:
    void do_print_info() const override;
public:
    snake()=default;
    snake(const string& species_name, const string& health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, const bool cold_blooded, const bool is_poisonous);
    snake(const snake& other);
    snake& operator=(const snake& other);
    ~snake()override=default;

    void print_details(ostream& os)const override;

    void make_sound()const override;
    animal* clone() const override;
    bool get_is_poisonous() const;

    void interesting_facts() const;
};
