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
void Directory::deleteFile(string fileName) {
    for (auto it = files.begin(); it != files.end(); ++it) {
        if (it->getName() == fileName) {
            it->setDeleted(true);
            cout << fileName << " deleted successfully.\n";
            return;
        }
    }
    cout << "File not found.\n";
}

void Directory::listContents() const {
    cout << "\nDirectory: " << name << endl;

    for (const auto &file : files) {
    if (!file.getDeleted()) {
        cout << "- " << file.getName() << endl;
    }
}

    for (const auto &dir : subdirectories) {
        cout << "[DIR] " << dir.getName() << endl;
    }
}

string Directory::getName() const {
    return name;
}
