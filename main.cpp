#include <iostream>
#include <string>
using namespace std;

class enclosure
{
private:
    string species;
    int number_of_animals, number_of_enclosures;
};

class animal
{
private:
    string name, health;
    int number, viewing_platform, male_number, female_number, attractiveness, enclosure_number;
    enclosure enclosure;
public:
    animal()=default;
};

class guest
{
private:
    string current_position;
public:
};

int main()
{

}

