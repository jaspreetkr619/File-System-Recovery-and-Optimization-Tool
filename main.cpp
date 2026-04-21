#include <iostream>
#include "core/File.h"
#include "core/Directory.h"
#include "core/StorageManager.h"

using namespace std;

int main() {

    int totalSpace = 100;
    int usedSpace = 0;

    StorageManager storage(10);

    Directory root("root");

    File file1("file1.txt", 10);
    file1.write("Hello World");

    cout << "\nSequential Read: " << file1.readSequential() << endl;
    cout << "Character at position 1: " << file1.readAt(1) << endl;
    cout << "Range (0-5): " << file1.readRange(0, 5) << endl;

    root.addFile(file1);
    usedSpace += file1.getSize();
    storage.allocateBlocks(2);

    Directory docs("docs");
    root.addDirectory(docs);

    File file2("file2.txt", 20);
    file2.write("This is inside docs folder");
    docs.addFile(file2);
    usedSpace += file2.getSize();
    storage.allocateBlocks(3);

    root.deleteFile("file1.txt");
    usedSpace -= file1.getSize();
    storage.freeBlocks(2);

    root.showAllContents();

    root.recoverFile("file1.txt");
    usedSpace += file1.getSize();
    storage.allocateBlocks(2);

    root.searchFile("file1.txt");
    docs.searchFile("file2.txt");

    root.listContents();
    docs.listContents();

    cout << "Free Space: " << totalSpace - usedSpace << endl;
    storage.displayStorageStatus();

    cout << "Active files in root: " << root.getActiveFileCount() << endl;
    cout << "Used Blocks: " << storage.getUsedBlockCount() << endl;
    cout << "Free Blocks: " << storage.getFreeBlockCount() << endl;


    return 0;
}
