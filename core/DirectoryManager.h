#ifndef DIRECTORY_MANAGER_H
#define DIRECTORY_MANAGER_H

#include "Directory.h"
#include "File.h"
#include "StorageManager.h"
#include<string>
#include <unordered_map>

class DirectoryManager {
private:
    Directory root;
    Directory current;
    StorageManager storage;
    std::unordered_map<std::string, int> fileBlockMap;
    int calculateBlocks(int size);

public:
    DirectoryManager(int totalBlocks);

    void createFolder(const std::string& name);
    void createFile(const std::string& name,int size);
    void deleteFile(const std::string& name,int blocks);
    void searchFile(const std::string& name) const;
    void listContents() const;
};

#endif
