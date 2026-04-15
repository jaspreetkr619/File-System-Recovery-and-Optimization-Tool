#include "File.h"

File::File(string name, int size) {
    this->name = name;
    this->size = size;
    this->content = "";
}

void File::write(string data) {
    content += data;
}

string File::read() const {
    return content;
}

string File::getName() const {
    return name;
}

int File::getSize() const {
    return size;
}
