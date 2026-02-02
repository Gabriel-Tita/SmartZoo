#ifndef OOP_APP_HPP
#define OOP_APP_HPP
#include "Zoo.hpp"
#include "ListOfEnclosures.hpp"
#include "Money.hpp"
#include "Guest.hpp"
#include "Lion.hpp"
#include "Eagle.hpp"
#include "Crocodile.hpp"
#include "Snake.hpp"
#include "Zooexception.hpp"
#include "AnimalFactory.hpp"
#include "CounterMap.hpp"
#include "Utils.hpp"

/**
 * @class App
 * @brief Entry point class used to run the application demo.
 *
 * Contains a single static method that runs a full example of the zoo simulation.
 */
class App {
public:
    /** @brief Runs the main demo logic of the project. */
    static void run();
};

#endif //OOP_APP_HPP
