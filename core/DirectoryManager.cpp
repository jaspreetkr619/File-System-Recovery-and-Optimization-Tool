#include "DirectoryManager.h"
#include<iostream>
using namespace std;

DirectoryManager::DirectoryManager() : root("root"), current("root") {}

void DirectoryManager::createFolder(const std::string& name) {
    Directory newDir(name);
    current.addDirectory(newDir);
    cout<< "Folder created: "<<name<<endl;
}

void DirectoryManager::createFile(const std::string& name,int size) {
    File newFile(name, size);
    current.addFile(newFile);
    cout << "File created: " <<name<<endl;
}

void DirectoryManager::searchFile(const std::string& name) const {
    current.searchFile(name);
}

void DirectoryManager::listContents() const {
    current.listContents();
}
