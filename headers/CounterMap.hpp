//
// Created by ciuch on 2/2/2026.
//

#ifndef OOP_COUNTERMAP_HPP
#define OOP_COUNTERMAP_HPP

#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

template<typename Key>
class CounterMap {
private:
    unordered_map<Key, int> cnt;

public:
    void add(const Key& key, int delta = 1) {
        cnt[key] += delta;
    }

    int get(const Key& key) const {
        auto it = cnt.find(key);
        if (it == cnt.end()) return 0;
        return it->second;
    }

    vector<pair<Key, int>> items() const {
        vector<pair<Key, int>> v;
        v.reserve(cnt.size());
        for (const auto& kv : cnt) v.push_back(kv);
        return v;
    }
};


#endif //OOP_COUNTERMAP_HPP