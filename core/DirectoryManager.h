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
    void listContents() const;
};

#endif
