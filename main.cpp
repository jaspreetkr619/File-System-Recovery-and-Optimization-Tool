#include <iostream>
#include "core/File.h"
#include "core/Directory.h"
#include "core/StorageManager.h"

using namespace std;

int main() {

    // Initialize storage
    int totalSpace = 100;
    int usedSpace = 0;

    StorageManager storage(10);

    Directory root("root");

    cout << "\n===== FILE CREATION =====\n";

    // Create file1
    File file1("file1.txt", 10);
    file1.write("Hello World");
    root.addFile(file1);
    usedSpace += file1.getSize();
    storage.allocateBlocks(2);

    // Create subdirectory
    Directory docs("docs");
    root.addDirectory(docs);

    // Create file2 inside docs
    File file2("file2.txt", 20);
    file2.write("This is inside docs folder");
    docs.addFile(file2);
    usedSpace += file2.getSize();
    storage.allocateBlocks(3);

    cout << "\n===== FILE ACCESS =====\n";

    // Sequential access
    cout << "Full Content: " << file1.readSequential() << endl;

    // Direct access
    cout << "Character at position 1: " << file1.readAt(1) << endl;

    // Range access
    cout << "First 5 characters: " << file1.readRange(0, 5) << endl;

    cout << "\n===== DELETE OPERATION =====\n";

    // Delete file1
    root.deleteFile("file1.txt");
    usedSpace -= file1.getSize();
    storage.freeBlocks(2);

    // Show all contents (including deleted)
    root.showAllContents();

    cout << "\n===== RECOVERY =====\n";

    // Recover file1
    root.recoverFile("file1.txt");
    usedSpace += file1.getSize();
    storage.allocateBlocks(2);

    cout << "\n===== SEARCH OPERATIONS =====\n";

    // Search files
    root.searchFile("file1.txt");
    docs.searchFile("file2.txt");

    cout << "\n===== FINAL STATUS =====\n";

    // Final directory contents
    root.listContents();
    docs.listContents();

    cout << "\n===== SYSTEM SUMMARY =====\n";

    // Space info
    cout << "Free Space: " << totalSpace - usedSpace << endl;

    // Block-level storage
    storage.displayStorageStatus();

    // Additional stats
    cout << "Active files in root: " << root.getActiveFileCount() << endl;
    cout << "Used Blocks: " << storage.getUsedBlockCount() << endl;
    cout << "Free Blocks: " << storage.getFreeBlockCount() << endl;

    return 0;
}