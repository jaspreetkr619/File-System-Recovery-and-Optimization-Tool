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
    for (auto &file : files) {
        if (file.getName() == fileName) {
            if (file.getDeleted()) {
                cout << fileName << " is already deleted.\n";
                return;
            }
            file.setDeleted(true);
            cout << fileName << " marked as deleted.\n";
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

void Directory::searchFile(string fileName) const {
    for (const auto &file : files) {
        if (!file.getDeleted() && file.getName() == fileName) {
            cout << "File found: " << fileName << endl;
            return;
        }
    }
    cout << "File not found\n";
}

string Directory::getName() const {
    return name;
}

void Directory::recoverFile(string fileName) {
    for (auto &file : files) {
        if (file.getName() == fileName) {
            if (!file.getDeleted()) {
                cout << fileName << " is already active.\n";
                return;
            }
            file.setDeleted(false);
            cout << fileName << " recovered successfully.\n";
            return;
        }
    }
    cout << "Deleted file not found.\n";
}

void Directory::showAllContents() const {
    cout << "\nDirectory (All Contents): " << name << endl;

    for (const auto &file : files) {
        cout << "- " << file.getName();
        if (file.getDeleted()) {
            cout << " [DELETED]";
        }
        cout << endl;
    }

    for (const auto &dir : subdirectories) {
        cout << "[DIR] " << dir.getName() << endl;
    }
}

int Directory::getActiveFileCount() const {
    int count = 0;
    for (const auto &file : files) {
        if (!file.getDeleted()) {
            count++;
        }
    }
    return count;
}