#include <iostream>
#include <unordered_map>

using namespace std;

// Cache storage
unordered_map<string, string> cache;

void putCache(string key, string value) {
    cache[key] = value;
    cout << "Cached: " << key << " -> " << value << endl;
}

string getCache(string key) {
    if (cache.find(key) != cache.end()) {
        cout << "Cache HIT for key: " << key << endl;
        return cache[key];
    } else {
        cout << "Cache MISS for key: " << key << endl;
        return "";
    }
}

void showCache() {
    cout << "\n--- Cache Contents ---\n";
    for (auto &pair : cache) {
        cout << pair.first << " -> " << pair.second << endl;
    }
}