#ifndef OOP_UTILS_HPP
#define OOP_UTILS_HPP

#include <iostream>
#include <string>
#include "CounterMap.hpp"

using namespace std;

/**
 * @brief Prints a simple histogram from a CounterMap.
 *
 * Displays each key with its associated counter value.
 *
 * @tparam Key Type of the keys stored in the CounterMap.
 * @param counter CounterMap containing the data.
 * @param title Title displayed above the histogram.
 */
template<typename Key>
void printHistogram(const CounterMap<Key> &counter, const string &title) {
    cout << "\n--- " << title << " ---\n";
    for (const auto &p: counter.items()) {
        cout << p.first << " -> " << p.second << "\n";
    }
    cout << "\n";
}

#endif //OOP_UTILS_HPP
