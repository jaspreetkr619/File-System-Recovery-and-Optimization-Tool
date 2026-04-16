#ifndef FILE_H
#define FILE_H

#include <string>
using namespace std;

class File {
private:
    string name;
    int size;
    string content;
    bool isDeleted;

public:
    File(string name, int size);
    void write(string data);
    string read() const;
    string getName() const;
    int getSize() const;
    void setDeleted(bool status);
    bool getDeleted() const;
};

#endif
