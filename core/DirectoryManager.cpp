#include "DirectoryManager.h"
#include<iostream>
using namespace std;

DirectoryManager::DirectoryManager() : root("root"), current("root") {}

void DirectoryManager::createFolder(const std::string& name) {
    Directory newDir(name);
    current.addDirectory(newDir);
    cout<< "Folder created: "<<name<<endl;
}

void DirectoryManager::listContents() const {
    current.listContents();
}
