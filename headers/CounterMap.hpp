#ifndef OOP_COUNTERMAP_HPP
#define OOP_COUNTERMAP_HPP

#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

/**
 * @class CounterMap
 * @brief Template class used to count occurrences of keys.
 *
 * Stores a mapping from keys to integer counters.
 */
template<typename Key>
class CounterMap {
private:
    /** @brief Internal map that stores counters. */
    unordered_map<Key, int> cnt;

public:
    /**
     * @brief Increases the counter for a given key.
     * @param key The key to update.
     * @param delta Value to add to the counter (default is 1).
     */
    void add(const Key& key, int delta = 1) {
        cnt[key] += delta;
    }

    /**
     * @brief Returns the counter value for a key.
     * @param key The key to query.
     * @return The counter value, or 0 if the key is not found.
     */
    int get(const Key& key) const {
        const auto it = cnt.find(key);
        if (it == cnt.end()) return 0;
        return it->second;
    }

    /**
     * @brief Returns all key-counter pairs.
     * @return Vector of pairs (key, counter).
     */
    vector<pair<Key, int>> items() const {
        vector<pair<Key, int>> v;
        v.reserve(cnt.size());
        for (const auto& kv : cnt) {
            v.emplace_back(kv.first, kv.second);
        }
        return v;
    }
};

#endif //OOP_COUNTERMAP_HPP
