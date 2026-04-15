#ifndef FILE_H
#define FILE_H

#include <string>
using namespace std;

class File {
private:
    string name;
    int size;
    string content;

public:
    File(string name, int size);
    void write(string data);
    string read() const;
    string getName() const;
    int getSize() const;
};

#endif
