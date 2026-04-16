#include <iostream>
#include "core/File.h"
#include "core/Directory.h"

using namespace std;

int main() {
    Directory root("root");

    File file1("file1.txt", 10);
    file1.write("Hello World");
    root.addFile(file1);

    Directory docs("docs");
    root.addDirectory(docs);

    File file2("file2.txt", 20);
    file2.write("This is inside docs folder");
    docs.addFile(file2);

    root.deleteFile("file1.txt");
    
    root.listContents();
    docs.listContents();

    return 0;
}
