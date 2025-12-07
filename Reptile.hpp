#pragma once
#include "animal.hpp"
class reptile : public animal {
private:
    bool cold_blooded=0;
public:
    reptile()=default;
    reptile(const string& species_name, const string& health, const int number, const int viewing_platform, const int male_number, const int female_number, const int attractiveness, const int enclosure_number, bool cold_blooded);
    reptile(const reptile& other);
    reptile& operator=(const reptile& other);
    ~reptile() override=default;

    virtual animal* clone() const override=0;
    virtual void make_sound() const override=0;

    void print_details(ostream& os)const override;

    void print_info() override;
    bool is_cold_blooded()const;
};
