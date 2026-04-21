#include "DirectoryManager.h"
#include<iostream>
using namespace std;

DirectoryManager::DirectoryManager(int totalBlocks)
    : root("root"), current("root"), storage(totalBlocks) {}

int DirectoryManager::calculateBlocks(int size){
    int blockSize=10;
    return (size + blockSize - 1)/blockSize; 
}

void DirectoryManager::createFolder(const std::string& name) {
    Directory newDir(name);
    current.addDirectory(newDir);
    cout<< "Folder created: "<<name<<endl;
}

void DirectoryManager::createFile(const std::string& name, int size) {
    int blocks = calculateBlocks(size);
    if (storage.allocateBlocks(blocks)) {
        File newFile(name, size);
        current.addFile(newFile);
        fileBlockMap[name] = blocks;
        cout << "File created: " << name 
             << " (Blocks: " << blocks << ")" << endl;
    } else {
        cout << "Not enough storage space" << endl;
    }
}

void DirectoryManager::deleteFile(const std::string& name) {
    current.deleteFile(name);
    if (fileBlockMap.find(name) != fileBlockMap.end()) {
        int blocks = fileBlockMap[name];
        deletedFiles[name] = {0, blocks};  
        storage.freeBlocks(blocks);
        fileBlockMap.erase(name);
        cout << "File soft deleted: " << name << endl;
    } else {
        cout << "File not found\n";
    }
}

void DirectoryManager::restoreFile(const std::string& name) {
    if (deletedFiles.find(name) != deletedFiles.end()) {
        int blocks = deletedFiles[name].blocks;
        if (storage.allocateBlocks(blocks)) {
            File restoredFile(name, 0); 
            current.addFile(restoredFile);
            fileBlockMap[name] = blocks;
            deletedFiles.erase(name);
            cout << "File restored: " << name << endl;
        } else {
            cout << "Not enough storage to restore file\n";
        }
    } else {
        cout << "No such deleted file\n";
    }
}

void DirectoryManager::searchFile(const std::string& name) const {
    current.searchFile(name);
}

void DirectoryManager::listContents() const {
    current.listContents();
}
