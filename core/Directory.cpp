#include "Directory.h"

Directory::Directory(string name) {
    this->name = name;
}

void Directory::addFile(File file) {
    files.push_back(file);
}

void Directory::addDirectory(Directory directory) {
    subdirectories.push_back(directory);
}

void Directory::listContents() const {
    cout << "\nDirectory: " << name << endl;

    for (const auto &file : files) {
        cout << "- " << file.getName() << endl;
    }

    for (const auto &dir : subdirectories) {
        cout << "[DIR] " << dir.getName() << endl;
    }
}

string Directory::getName() const {
    return name;
}
