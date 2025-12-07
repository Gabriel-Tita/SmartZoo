#pragma once
#include "animal.hpp"

class mammal : public animal{
private:
    bool has_fur=0;
protected:
    void do_print_info()const override;
public:
    mammal()=default;
    mammal(const string& species_name, const string& health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, const bool has_fur);
    mammal(const mammal& other);
    mammal& operator=(const mammal& other);
    ~mammal() override = default;

    virtual animal* clone() const override=0;
    virtual void make_sound() const override=0;

    void print_details(ostream& os)const override;

    bool get_has_fur()const;
};
