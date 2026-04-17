#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <vector>
#include <iostream>
using namespace std;

class StorageManager {
private:
    vector<int> blocks;
    int totalBlocks;

public:
    StorageManager(int totalBlocks);
    bool allocateBlocks(int numBlocks);
    void freeBlocks(int numBlocks);
    void displayStorageStatus() const;
};

#endif
