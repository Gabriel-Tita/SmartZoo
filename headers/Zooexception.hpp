#pragma once
#include <stdexcept>
#include <string>
using namespace std;

/**
 * @class ZooException
 * @brief Base class for all custom zoo-related exceptions.
 *
 * Inherits from std::runtime_error and stores an error message.
 */
class ZooException : public std::runtime_error {
public:
    /**
     * @brief Constructs a ZooException with a message.
     * @param message Error message.
     */
    explicit ZooException(const string &message) : std::runtime_error(message) {
    }
};

/**
 * @class InvalidInputException
 * @brief Exception thrown when an invalid input is provided.
 */
class InvalidInputException : public ZooException {
public:
    /**
     * @brief Constructs an InvalidInputException.
     * @param input_value The invalid input value.
     */
    explicit InvalidInputException(const string &input_value)
        : ZooException("Eroare la input: Valoarea '" + input_value + "' nu este permisa!") {
    }
};

/**
 * @class AnimalNotFoundException
 * @brief Exception thrown when a species is not found in the zoo.
 */
class AnimalNotFoundException : public ZooException {
public:
    /**
     * @brief Constructs an AnimalNotFoundException.
     * @param species_name Name of the species that was not found.
     */
    explicit AnimalNotFoundException(const string &species_name)
        : ZooException("Eroare de cautare: Specia " + species_name + " nu a fost gasita in zoo!") {
    }
};

/**
 * @class CloningFailureException
 * @brief Exception thrown when cloning an animal fails.
 */
class CloningFailureException : public ZooException {
public:
    /**
     * @brief Constructs a CloningFailureException.
     * @param species_name Name of the species that failed to clone.
     */
    explicit CloningFailureException(const string &species_name)
        : ZooException("Eroare la clonare: Esec la alocarea memoriei pentru specia: " + species_name + ".") {
    }
};
