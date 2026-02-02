#ifndef OOP_UTILS_HPP
#define OOP_UTILS_HPP

#include <iostream>
#include <string>
#include "CounterMap.hpp"

using namespace std;

template<typename Key>
void print_histogram(const CounterMap<Key>& counter, const string& title) {
    cout << "\n--- " << title << " ---\n";
    for (const auto& p : counter.items()) {
        cout << p.first << " -> " << p.second << "\n";
    }
    cout << "\n";
}


#endif //OOP_UTILS_HPP