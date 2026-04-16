#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <vector>
#include <string>
#include <iostream>
#include "File.h"

using namespace std;

class Directory {
private:
    string name;
    vector<File> files;
    vector<Directory> subdirectories;

public:
    Directory(string name);
    void addFile(File file);
    void addDirectory(Directory directory);
    void deleteFile(string fileName);
    void listContents() const;
    string getName() const;
    void searchFile(string fileName) const;
};

#endif
