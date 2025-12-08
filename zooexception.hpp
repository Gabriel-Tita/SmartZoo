#pragma once
#include <stdexcept>
#include <string>
using namespace std;

class zooexception : public std::runtime_error {
public:
    explicit zooexception(const string& message): std::runtime_error(message) {}
};

class invalid_input_exception :public zooexception {
public:
    explicit invalid_input_exception(const string& input_value)
        : zooexception("Eroare la input: Valoarea '"+ input_value +"' nu este permisa!") {}
};

class animal_not_found_exception :public zooexception {
public:
    explicit animal_not_found_exception(const string& species_name)
        : zooexception("Eroare de cautare: Specia "+ species_name+" nu a fost gasita in zoo!") {}
};

class cloning_failure_exception :public zooexception {
public:
    explicit cloning_failure_exception(const string& species_name)
        :zooexception("Eroare la clonare: Esec la alocarea memoriei pentru specia: " + species_name + ".") {}
};
