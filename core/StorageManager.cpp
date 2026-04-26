#include "StorageManager.h"

StorageManager::StorageManager(int totalBlocks) {
    this->totalBlocks = totalBlocks;
    blocks.resize(totalBlocks, 0); // 0 means free
}

bool StorageManager::allocateBlocks(int numBlocks) {
    int count = 0;

    for (int i = 0; i < totalBlocks; i++) {
        if (blocks[i] == 0) {
            blocks[i] = 1;
            count++;
            if (count == numBlocks) {
                return true;
            }
        }
    }

    return false; // not enough space
}

void StorageManager::freeBlocks(int numBlocks) {
    int count = 0;

    for (int i = 0; i < totalBlocks; i++) {
        if (blocks[i] == 1) {
            blocks[i] = 0;
            count++;
            if (count == numBlocks) {
                return;
            }
        }
    }
}

void StorageManager::displayStorageStatus() const {
    cout << "\nStorage Blocks: ";
    for (int i = 0; i < totalBlocks; i++) {
        cout << blocks[i] << " ";
    }
    cout << endl;
}

int StorageManager::getUsedBlockCount() const {
    int count = 0;
    for (int block : blocks) {
        if (block == 1) count++;
    }
    return count;
}

int StorageManager::getFreeBlockCount() const {
    int count = 0;
    for (int block : blocks) {
        if (block == 0) count++;
    }
    return count;
}
