#pragma once
#include <stdexcept>
#include <string>
using namespace std;

class ZooException : public std::runtime_error {
public:
    explicit ZooException(const string &message) : std::runtime_error(message) {
    }
};

class InvalidInputException : public ZooException {
public:
    explicit InvalidInputException(const string &input_value)
        : ZooException("Eroare la input: Valoarea '" + input_value + "' nu este permisa!") {
    }
};

class AnimalNotFoundException : public ZooException {
public:
    explicit AnimalNotFoundException(const string &species_name)
        : ZooException("Eroare de cautare: Specia " + species_name + " nu a fost gasita in zoo!") {
    }
};

class CloningFailureException : public ZooException {
public:
    explicit CloningFailureException(const string &species_name)
        : ZooException("Eroare la clonare: Esec la alocarea memoriei pentru specia: " + species_name + ".") {
    }
};
