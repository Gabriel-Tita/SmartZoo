#include "App.hpp"
#include <iostream>

/**
 * @brief Runs a demo scenario for the zoo application.
 *
 * Creates animals and enclosures, simulates visitors, tests features
 * (printing, feeding, cloning, factory creation) and basic exception handling.
 */
void App::run() {

    CounterMap<string> animalTypes;
    ListOfEnclosures list;
    Money wallet(0);
    Guest guest(10, 100, 100, 0);

    Zoo mySmartZoo;

    const Lion lion1("Lion", "Good", 2, 1, 1, 1, 80, 1, true, "Golden");
    const Snake snake1("Python", "Fair", 1, 0, 0, 1, 60, 1, true, true);
    const Eagle eagle1("Golden Eagle", "Excellent", 3, 2, 2, 1, 95, 1, true, 2.0);

    mySmartZoo.add(lion1);
    animalTypes.add("lion");
    mySmartZoo.add(snake1);
    animalTypes.add("snake");
    mySmartZoo.add(eagle1);
    animalTypes.add("eagle");
    mySmartZoo.dailyFeedAndSound();

    cout << "\nThere are " << mySmartZoo.getNumberOfFamilies() << " families of animals.\n\n";

    const Enclosure lionEnclosure("Lion", 4, 1, 2);
    const Enclosure snakeEnclosure("Snake", 5, 1, 2);
    const Enclosure eagleEnclosure("Eagle", 6, 1, 2);

    list.add(lionEnclosure);
    list.add(snakeEnclosure);
    list.add(eagleEnclosure);
    cout << "\nThere are " << list.getNumberOfEnclosures() << " enclosures.\n\n";

    const Lion lion2("Lion", "Good", 2, 1, 1, 1, 80, 1, true, "Golden");
    const Enclosure lion2Enclosure("Lion", 4, 1, 2);
    lion2.printInfo();
    lion2Enclosure.printInfo();
    list.printInfo();

    const Lion lion3 = lion2;
    Lion lion4;
    lion4 = lion3;
    lion3.printInfo();
    cout << lion4;

    guest.generateGuests(list);
    cout << guest;

    CounterMap<string> visitorsBySpecies;

    for (const auto& s : guest.getPositions()) {
        visitorsBySpecies.add(s);
    }

    cout << "--- Visitors per enclosure/species ---\n";
    for (const auto& p : visitorsBySpecies.items()) {
        cout << "    " << p.first << " -> " << p.second << "\n";
    }

    list.queryAddAnimal(mySmartZoo, "Lion", "Male");
    cout << list;

    guest.calculateRating(mySmartZoo);
    guest.calculateNumberOfFreeEmptySpaces();
    guest.guestIncoming(wallet, 100, list);
    cout << wallet;
    guest.calculateNumberOfFreeEmptySpaces();

    cout << eagle1;
    cout << snake1;
    cout << lion1;

    cout << "----Interesting Facts----\n";
    lion1.interestingFacts();
    snake1.interestingFacts();
    eagle1.interestingFacts();

    const Crocodile croc1("Australian Crocodile", "Great", 1, 3, 1, 0, 97, 1, true, true);
    animalTypes.add("crocodile");
    mySmartZoo.add(croc1);

    const Enclosure crocEnclosure("Crocodile", 5, 1, 1);
    list.add(crocEnclosure);
    list.printInfo();
    croc1.printInfo();
    mySmartZoo.dailyFeedAndSound();
    cout << "\nThere are " << mySmartZoo.getNumberOfFamilies() << " families of animals.\n\n";
    cout << "\nThere are " << list.getNumberOfEnclosures() << " enclosures.\n\n";

    mySmartZoo.simulateDay(std::cout);

    /// using prototype pattern
    Lion l("Lion", "Healthy", 10, 1, 4, 6, 9, 2, true, "Golden");

    const Animal& base = l;
    std::unique_ptr<Animal> copy(base.clone());

    std::cout << "Original:\n";
    base.printInfo();

    std::cout << "\nClone:\n";
    copy->printInfo();

    mySmartZoo.add(l);
    mySmartZoo.printInfo();

    AnimalFactory factory;

    auto a1 = factory.create("lion");
    auto a2 = factory.create("snake");

    mySmartZoo.add(*a1);
    mySmartZoo.add(*a2);

    printHistogram(animalTypes, "Animals by species");

    try {
        ///my_smart_zoo.add_individual("tiger", "red");
        ///my_smart_zoo.add_individual("tiger", "Male");
    } catch (const InvalidInputException &e) {
        cerr << "\n[Prins invalid_input_exception]: Detaliu: " << e.what() << "\n";
    } catch (const AnimalNotFoundException &e) {
        cerr << "\n[Animal_not_found_exception]: Detaliu: " << e.what() << "\n";
    } catch (const CloningFailureException &e) {
        cerr << "\n[Cloning_failure_exception]: Detaliu: " << e.what() << "\n";
    } catch (const ZooException &e) {
        cerr << "\n[EROARE GENERICA]: o exceptie necunoscuta a fost prinsa. Detaliu: " << e.what() << "\n";
    } catch (const std::exception &e) {
        std::cerr << "[EROARE CRITICA STANDARD C++]: Programul a intampinat o eroare standard. Detaliu:" << e.what()
                  << "\n";
    }
}
