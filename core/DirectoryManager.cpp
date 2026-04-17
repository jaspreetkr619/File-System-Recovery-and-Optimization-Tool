#include "DirectoryManager.h"
#include<iostream>
using namespace std;

DirectoryManager::DirectoryManager(int totalBlocks)
    : root("root"), current("root"), storage(totalBlocks) {}

void DirectoryManager::createFolder(const std::string& name) {
    Directory newDir(name);
    current.addDirectory(newDir);
    cout<< "Folder created: "<<name<<endl;
}

void DirectoryManager::createFile(const std::string& name, int size, int blocks) {
    if (storage.allocateBlocks(blocks)) {
        File newFile(name,size);
        current.addFile(newFile);
        cout << "File created: " <<name<<endl;
    } else {
        cout << "Not enough storage space\n";
    }
}

void DirectoryManager::deleteFile(const std::string& name, int blocks) {
    current.deleteFile(name);
    storage.freeBlocks(blocks);
    cout << "Storage freed for file: " <<name<<endl;
}

void DirectoryManager::searchFile(const std::string& name) const {
    current.searchFile(name);
}

void DirectoryManager::listContents() const {
    current.listContents();
}
