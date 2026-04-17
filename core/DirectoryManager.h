#ifndef DIRECTORY_MANAGER_H
#define DIRECTORY_MANAGER_H

#include "Directory.h"
#include<string>

class DirectoryManager {
private:
    Directory root;
    Directory current;

public:
    DirectoryManager();

    void createFolder(const std::string& name);
    void createFile(const std::string& name,int size);
    void searchFile(const std::string& name) const;
    void listContents() const;
};

#endif
