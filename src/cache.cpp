#include "cache.h"
#include <iostream>
#include <fstream>
#include <unordered_map>


using namespace std;

string CACHE_FILE = "C:\\Users\\Varnika Sharma\\Desktop\\File_Recovery_Tool\\File-System-Recovery-and-Optimization-Tool\\data\\cache.txt";
string STATS_FILE = "C:\\Users\\Varnika Sharma\\Desktop\\File_Recovery_Tool\\File-System-Recovery-and-Optimization-Tool\\data\\cache_stats.txt";

// Load cache from file
unordered_map<string, string> loadCache() {
    unordered_map<string, string> cache;
    ifstream file(CACHE_FILE);

    string key, value;
    while (file >> key >> value) {
        cache[key] = value;
    }

    file.close();
    return cache;
}

// Save cache to file
void saveCache(unordered_map<string, string>& cache) {
    ofstream file(CACHE_FILE);

    for (auto &entry : cache) {
        file << entry.first << " " << entry.second << endl;
    }

    file.close();
}

// Load stats
void loadStats(int &hits, int &misses) {
    ifstream file(STATS_FILE);

    if (!(file >> hits >> misses)) {
    hits = 0;
    misses = 0;
}

    file.close();
}

// Save stats
void saveStats(int hits, int misses) {
    ofstream file(STATS_FILE);
    file << hits << " " << misses;
    file.close();
}

// GET
string getFromCache(string key) {
    auto cache = loadCache();

    int hits, misses;
    loadStats(hits, misses);

    if (cache.find(key) != cache.end()) {
        hits++;
        saveStats(hits, misses);
        return cache[key];
    } else {
        misses++;
        saveStats(hits, misses);
        return "";
    }
}

// PUT
void putCache(string key, string value) {
    auto cache = loadCache();
    cache[key] = value;
    saveCache(cache);
    cout << "CACHE FUNCTION CALLED\n";
}

// SHOW
void showCache() {
    auto cache = loadCache();

    int hits, misses;
    loadStats(hits, misses);

    cout << "--- Cache Contents ---\n";

    for (auto &entry : cache) {
        cout << entry.first << " -> " << entry.second << endl;
    }

    cout << "Cache Stats:\n";
    cout << "Hits: " << hits << endl;
    cout << "Misses: " << misses << endl;
}