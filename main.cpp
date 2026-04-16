#include <iostream>
#include "core/File.h"
#include "core/Directory.h"

using namespace std;

int main() {
    // Step 1: Initialize storage
    int totalSpace = 100;
    int usedSpace = 0;
    
    Directory root("root");

    // Create file1
    File file1("file1.txt", 10);
    file1.write("Hello World");
    root.addFile(file1);

    // Track space
    usedSpace += file1.getSize();

    // Create directory
    Directory docs("docs");
    root.addDirectory(docs);

    // Create file2
    File file2("file2.txt", 20);
    file2.write("This is inside docs folder");
    docs.addFile(file2);

    // Track space
    usedSpace += file2.getSize();

    // Delete file1
    root.deleteFile("file1.txt");

    //Search files
    root.searchFile("file1.txt");
    root.searchFile("file2.txt");

    // Display contents
    root.listContents();
    docs.listContents();

    // Show free space
    cout << "Free Space: " << totalSpace - usedSpace << endl;

    return 0;
}
