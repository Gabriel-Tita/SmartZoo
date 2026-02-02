#include "AnimalFactory.hpp"
#include <stdexcept>
using namespace std;

AnimalFactory::AnimalFactory() {
    creators["lion"] = []() {
        return std::make_unique<lion>("Lion", "Good", 2, 1, 1, 1, 80, 1, true, "Golden");
    };
    creators["snake"] = []() {
        return std::make_unique<snake>("Python", "Fair", 1, 0, 0, 1, 60, 1, true, true);
    };
    creators["eagle"] = []() {
        return std::make_unique<eagle>("Golden Eagle", "Excellent", 3, 2, 2, 1, 95, 1, true, 2.0);
    };
    creators["crocodile"] = []() {
        return std::make_unique<crocodile>("Australian Crocodile", "Great", 1, 3, 1, 0, 97, 1, true, true);
    };
}

unique_ptr<animal> AnimalFactory::create(const string& type) const {
    auto it = creators.find(type);
    if (it == creators.end())
        throw std::runtime_error("Unknown animal type: " + type);

    return it->second(); // creează obiectul
}
