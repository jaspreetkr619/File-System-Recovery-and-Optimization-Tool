#include "DirectoryManager.h"

DirectoryManager::DirectoryManager()
    : current("root"), storage(10) {}

void DirectoryManager::createFolder(const string& name) {
    Directory folder(name);
    current.addDirectory(folder);
    cout << "Folder created: " << name << endl;
}

void DirectoryManager::createFile(const string& name, int size, int blocks) {
    if (storage.allocateBlocks(blocks)) {
        File file(name, size);
        current.addFile(file);
        fileBlockMap[name] = blocks;
        cout << "File created: " << name << endl;
    } else {
        cout << "Not enough storage space to create file\n";
    }
}

void DirectoryManager::deleteFile(const string& name) {
    current.deleteFile(name);

    if (fileBlockMap.find(name) != fileBlockMap.end()) {
        int blocks = fileBlockMap[name];
        deletedFileBlockMap[name] = blocks;
        storage.freeBlocks(blocks);
        fileBlockMap.erase(name);

        cout << "File soft deleted from storage map: " << name << endl;
    } else {
        cout << "File not found in active storage map\n";
    }
}

void DirectoryManager::restoreFile(const string& name) {
    current.recoverFile(name);

    if (deletedFileBlockMap.find(name) != deletedFileBlockMap.end()) {
        int blocks = deletedFileBlockMap[name];

        if (storage.allocateBlocks(blocks)) {
            fileBlockMap[name] = blocks;
            deletedFileBlockMap.erase(name);
            cout << "File restored in storage map: " << name << endl;
        } else {
            cout << "Not enough storage space to restore file\n";
        }
    } else {
        cout << "Deleted file not found in recovery map\n";
    }
}

void DirectoryManager::searchFile(const string& name) const {
    current.searchFile(name);
}

void DirectoryManager::listContents() const {
    current.listContents();
    storage.displayStorageStatus();
}