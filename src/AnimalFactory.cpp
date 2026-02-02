#include "AnimalFactory.hpp"
#include <stdexcept>

AnimalFactory::AnimalFactory() {
    creators["lion"] = []() {
        return make_unique<Lion>("Lion", "Good", 2, 1, 1, 1, 80, 1, true, "Golden");
    };
    creators["snake"] = []() {
        return make_unique<Snake>("Python", "Fair", 1, 0, 0, 1, 60, 1, true, true);
    };
    creators["eagle"] = []() {
        return make_unique<Eagle>("Golden Eagle", "Excellent", 3, 2, 2, 1, 95, 1, true, 2.0);
    };
    creators["crocodile"] = []() {
        return make_unique<Crocodile>("Australian Crocodile", "Great", 1, 3, 1, 0, 97, 1, true, true);
    };
}

unique_ptr<Animal> AnimalFactory::create(const string& type) const {
    const auto it = creators.find(type);
    if (it == creators.end())
        throw runtime_error("Unknown animal type: " + type);

    return it->second(); // creează obiectul
}
