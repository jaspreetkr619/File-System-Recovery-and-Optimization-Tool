#ifndef DIRECTORYMANAGER_H
#define DIRECTORYMANAGER_H

#include <iostream>
#include <string>
#include <unordered_map>

#include "Directory.h"
#include "File.h"
#include "StorageManager.h"

using namespace std;

class DirectoryManager {
private:
    Directory current;
    StorageManager storage;
    unordered_map<string, int> fileBlockMap;
    unordered_map<string, int> deletedFileBlockMap;

public:
    DirectoryManager();

    void createFolder(const string& name);
    void createFile(const string& name, int size, int blocks);
    void deleteFile(const string& name);
    void restoreFile(const string& name);
    void searchFile(const string& name) const;
    void listContents() const;
};

#endif